#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include "consoleapp.h"
#include "pve.h"
#include "items_list.h"
#include "trader.h"
using namespace std;



void map_menu(Player& player) {
	if (player.in_battle) {
		return;
	}
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/map.txt");

		int input = _getch();
		Enemy enemy = get_enemy();
		switch (input) {
		case 49: // 1
			trader_menu(player);
			break;
		case 50: // 2
			arena_menu(player);
			break;
		case 51: // 3
			boss(player);
			break;
		case 113: // Q
			save(player);
			menu_is_on = false;
			break;
		}
		cls();
	}
}


void inventory_menu(Player& player) {
	if (player.in_battle) {
		return;
	}
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		ccout("HP:", 4, 0);
		cout << " " << player.get_hp() << " / " << player.get_full_hp() << "\n";
		ccout("XP:", 2, 0);
		cout << " " << player.get_xp() << "\n";
		player_items_print(player);

		int input = _getch();
		switch (input) {
		case 113: // Q
			save(player);
			return;
		}
		cls();
	}
}


int skill_points_menu(int(&skills)[5], int points) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		if (points > 0) {
			cout << "Вам доступно " << points << " очков умений\n";
			cout << "Чтобы распределить их нажмите:\n";
			txt_message_skills("txt/skill_menu.txt", skills);
		}
		else {
			cout << "У вас не осталось очков умений\n";
		}

		int choose = _getch();
		switch (choose) {
		case 49: // 1
			skills[0]++;
			points--;
			break;
		case 50: // 2
			skills[1]++;
			points--;
			break;
		case 51: // 3
			skills[2]++;
			points--;
			break;
		case 52: // 4
			skills[3]++;
			points--;
			break;
		case 53: // 5
			skills[4]++;
			points--;
			break;
		case 113: // Q
			menu_is_on = false;
			break;
		}
		cls();
	}
	return points;
}


void upgrade_skills(Player& player) {
	int skills_list[5];
	player.skills_to_list(skills_list);
	int free_points = skill_points_menu(skills_list, player.get_skillpoints());
	player.set_skillpoints(free_points);
	player.list_to_skills(skills_list);
}

#endif
