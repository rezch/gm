#ifndef PVE_H
#define PVE_H
#include <iostream>
#include <string>
#include "consoleapp.h"
#include "itemsdrop.h"
#include "locations.h"
using namespace std;


void location_lock(Player& player, int points_needed) {
	cls();
	int points = points_needed - player.get_xp();
	cout << "��� ������� ";
	ccout(to_string(player.get_level()), 2, false);
	cout << "��� ���������� �������� ��� " << points << " ����� �����, ����� �������������� ������\n";
	_getch();
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

	ccout("��� HP:", 160, false);
	cout << " ";
	ccout(string(player_hp_bar, '*'), 160, false);
	ccout(string(10 - player_hp_bar, '*'), 64, false);
	cout << " (" << player.get_hp() << " / " << player.get_full_hp() << ')' << endl;
	cout << "\n";
	ccout(enemy.name + ':', 64, false);
	cout << " ";
	ccout(string(enemy_hp_bar, '*'), 160, false);
	ccout(string(10 - enemy_hp_bar, '*'), 64, false);
	cout << " (" << enemy.get_hp() << ')' << endl;
}


void item_drop(Player& player, Location& location, bool is_boss) {
	if (random(0, 100) < 65) return;

	pair <int, int> item;
	item = get_random_item_id();
	if (is_boss) item = get_random_legendary_item_id();
	cout << item.first << endl;
	switch (item.first) {
	case 0:
		dropped_item_choose(player, weapons_list[item.second]);
		break;
	case 1:
		dropped_item_choose(player, (Helmet&)helmets_list[item.second]);
		break;
	case 2:
		dropped_item_choose(player, (Chestplate&)chestplate_list[item.second]);
		break;
	case 3:
		dropped_item_choose(player, (Leggings&)leggings_list[item.second]);
		break;
	case 4:
		dropped_item_choose(player, (Boots&)boots_list[item.second]);
		break;
	}
}


void fight(Player& player, Enemy& enemy, Location& location, bool is_boss) {
	player.in_battle = true;
	int last_hp = player.get_hp();

	cls();
	cout << "���� ��� �������� ";
	ccout(enemy.name, 64, true);
	cout << enemy.description << "\n";
	_getch();

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

			cout << "�� ������� " << player_attack << " �����\n\n";
            cout << player.get_weapon().damage << ' ' << player.weapon_upgrade_k << ' ' << player.get_skills()["agility"] << ' ' << player.get_skills()["power"] << endl;
			cout << "������� ���� " << enemy_attack << "\n";

			info_print(player, enemy);
		}
		else if (action == 50) { // 2
			player_attack = player.parrying(enemy_attack);
			enemy.take_damage(player_attack);

			cout << "�� ������� " << player_attack << " �����\n\n";
			cout << "������� ���� " << enemy_attack << "\n";

			info_print(player, enemy);
		}
	}

	cls();

	if (!player.is_dead()) {
		item_drop(player, location, is_boss);
		int points = random(0, 11) / 10; // 0 - 1
		int coins = (int)sqrt(random(0, 10000)); // 0 - 100

		cout << "�� ��������:\n" << points << " ����� ������\n";
		cout << enemy.get_xp() << " �����\n";
		cout << coins << "  �����\n";

		player.add_money(coins);
		player.add_skillpoints(points);
		player.add_xp(enemy.get_xp());
		player.in_battle = false;

		save(player);
	}
	else {
		cout << "�� ���������...\n";
		player.add_hp(last_hp);
		player.in_battle = false;
	}
	_getch();
}


void arena_menu(Player& player, Location& location) {
	while (true) {
		cls();
		cout << "�� ������ � ";
        cout << location.name() << "\n";
		cout << location.description() << "\n";
		txt_message("txt/arena.txt");

		int input = _getch();
		if (input == 49) { // 1
            Enemy enemy = location.get_enemy();
			fight(player, enemy, location, false);
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
		cout << "������� �� �����, �� ������� � ���������� �����, ������� ����� �������� �����" << "\n";
		txt_message("txt/arena.txt");

		int input = _getch();
		if (input == 49) { // 1
            Enemy enemy = location.get_boss();
			fight(player, enemy, location, true);
		}
		else if (input == 50 || input == 113) { // 2|Q
			return;
		}
	}
}


#endif
