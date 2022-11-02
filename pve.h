#ifndef PVE_H
#define PVE_H
#include <iostream>
#include <string>
#include "progress_save.h"
#include "enemies.h"
#include "consoleapp.h"
#include "itemsdrop.h"
#include "locations.h"
using namespace std;


void location_lock(Player& player, int points_needed) {
	cls();
	int points = points_needed - player.get_xp();
	cout << "Ваш уровень ";
	ccout(to_string(player.get_level()), 2, 1);
	cout << "Вам необходимо получить еще " << points << " очков опыта, чтобы разблокировать боссов\n";
	int input = _getch();
	cls();
}


void info_print(Player& player, Enemy& enemy) {
	int player_hp_bar = 0;
	if (!player.is_dead()) {
		player_hp_bar = 10 * player.get_hp() / player.get_full_hp();
	}
	int enemy_hp_bar = 0;
	if (!enemy.is_dead()) {
		enemy_hp_bar = 10 * enemy.get_hp() / enemy.full_hp;
	}

	ccout("Ваш HP:", 160, 0);
	cout << " ";
	ccout(string(player_hp_bar, '*'), 160, 0);
	ccout(string(10 - player_hp_bar, '*'), 64, 0);
	cout << " (" << player.get_hp() << ')' << endl;
	cout << "\n";
	ccout(enemy.name + ':', 64, 0);
	cout << " ";
	ccout(string(enemy_hp_bar, '*'), 160, 0);
	ccout(string(10 - enemy_hp_bar, '*'), 64, 0);
	cout << " (" << enemy.get_hp() << ')' << endl;
}


void item_drop(Player& player, Location& location, bool is_boss) {
	//if (random(0, 100) < 65) return;
	
	auto item = location.get_random_item();
	dropped_item_choose(player, item);
}


void fight(Player& player, Enemy& enemy, Location& location, bool is_boss) {
	player.in_battle = true;
	int last_hp = player.get_hp();

	cls();
	cout << "Вами был встречен ";
	ccout(enemy.name, 64, 1);
	cout << enemy.description << "\n";

	int input = _getch();
	cls();
	info_print(player, enemy);

	while (!enemy.is_dead() && !player.is_dead()) {
		txt_message("txt/attack_choose.txt");
		int action = _getch();
		int player_attack = player.attack();
		int enemy_attack = enemy.attack();
		cls();
		if (action == 49) { // 1
			enemy.take_damage(player_attack);
			player.take_damage(enemy_attack);
			cout << "Вы нанесли " << player_attack << " урона\n\n";
			cout << "Получен урон " << enemy_attack << "\n";
			info_print(player, enemy);
		}
		else if (action == 50) { // 2
			player_attack = player.parrying(enemy_attack);
			enemy.take_damage(player_attack);
			cout << "Вы нанесли " << player_attack << " урона\n\n";
			cout << "Получен урон " << enemy_attack << "\n";
			info_print(player, enemy);
		}
	}
	cls();
	if (!player.is_dead()) {
		item_drop(player, location, is_boss);
		int points = random(0, 11) / 10; // 0 - 1
		int coins = sqrt(random(0, 10000)); // 0 - 100

		cout << "Вы получили:\n" << points << " очков умений\n";
		cout << enemy.get_xp() << " опыта\n";
		cout << coins << "  монет\n";

		player.add_money(coins);
		player.add_skillpoints(points);
		player.add_xp(enemy.get_xp());
		player.in_battle = false;
		save(player);
	}
	else {
		cout << "Вы проиграли...\n";
		player.add_hp(last_hp);
		player.in_battle = false;
	}
	input = _getch();
}


void arena_menu(Player& player, Location& location) {
	while (true) {
		cls();
		cout << "Вы попали в " << location.name << "\n";
		cout << location.description << "\n";
		txt_message("txt/arena.txt");

		Enemy enemy = location.get_enemy();

		int input = _getch();
		if (input == 49) { // 1
			fight(player, enemy, location, 0);
		}
		else if (input == 50 || input == 113) { // 2|Q
			return;
		}
	}
}


void boss_menu(Player& player, Location& location) {
	if (player.get_level() < 50) {
		location_lock(player, 500);
		return;
	}
	while (true) {
		cls();
		cout << "Блуждая по лесам, вы забрели в непонятное место, кажется скоро начнется битва" << "\n";
		txt_message("txt/arena.txt");
		Enemy enemy = location.get_boss();
		int input = _getch();
		if (input == 49) { // 1
			fight(player, enemy, location, 1);
		}
		else if (input == 50 || input == 113) { // 2|Q
			return;
		}
	}
}


#endif
