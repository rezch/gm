#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include <cmath>
#include "consoleapp.h"
#include "pve.h"
#include "items_list.h"
#include "map.h"
using namespace std;


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
