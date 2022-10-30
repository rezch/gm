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
	while (true) {
		cls();
		player_info_print(player);
		player_items_print(player);

		if (_getch() == 113) return; // Q
	}
}


int skill_points_menu(int(&skills)[5], int points) {
	while (true) {
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
		if (choose > 48 && choose < 54) { // 1 - 5
			skills[choose - 49]++;
		}

		cls();
		if (choose == 113) break;
	}
	return points;
}


void upgrade_skills_menu(Player& player) {
	int skills_list[5];
	player.skills_to_list(skills_list);
	int free_points = skill_points_menu(skills_list, player.get_skillpoints());
	player.set_skillpoints(free_points);
	player.list_to_skills(skills_list);
	save(player);
}

#endif
