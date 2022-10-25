#ifndef PVE_H
#define PVE_H
#include <iostream>
#include <string>
#include "progress_save.h"
#include "enemies.h"
#include "consoleapp.h"
using namespace std;


Enemy get_enemy() {
	return enemylist[random(0, enemy_count)];
}


void info_print(Player& player, Enemy& enemy) {
	int player_hp_bar = 0;
	if (!player.is_dead()) {
		player_hp_bar = 10 * player.get_hp() / player.full_hp;
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


int action_choose() {
	while (true) {
		int input = _getch();
		switch (input) {
		case 49: // 1
			return 1;
		case 50: // 2
			return 2;
		case 51: // 3
			return 3;
		}
	}
	return 0;
}


void fight(Player& player) {
	player.in_battle = true;
	Enemy enemy = get_enemy();
	int last_hp = player.get_hp();

	cls();
	cout << "Вы встертили ";
	ccout(enemy.name, 64, 1);
	cout << enemy.description << "\n";

	int input = _getch();
	cls();
	info_print(player, enemy);

	while (!enemy.is_dead() && !player.is_dead()) {
		txt_message("txt/attack_choose.txt");
		int action = action_choose();
		int player_attack = player.attack();
		int enemy_attack = enemy.attack();
		cls();
		switch (action) {
		case 1:
			enemy.take_damage(player_attack);
			player.take_damage(enemy_attack);
			cout << "Вы нанесли " << player_attack << " урона\n\n";
			cout << "Получен урон " << enemy_attack << "\n";
			info_print(player, enemy);
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	cls();
	if (!player.is_dead()) {
		cout << "Вы получили: " << enemy.get_xp() << " опыта\n";
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


void arena_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/arena.txt");

		int input = _getch();
		switch (input) {
		case 49: // 1
			fight(player);
			break;
		case 50: // 2
			menu_is_on = false;
			break;
		case 113: // Q
			menu_is_on = false;
			break;
		}
		cls();
	}
}


#endif
