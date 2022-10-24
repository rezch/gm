#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "items.h"
#include "CREATURES.H"
#include "progress_save.h"
#include "items_list.h"
using namespace std;


const map <string, int> rarity = {
	{"default", 0},
	{"rare", 1},
	{"epic", 2},
	{"legend", 3},
};


void cls() {
	system("cls");
}


void txt_message(string filename) {
	ifstream file(filename, ios::in);
	while (true) {
		string line;
		getline(file, line);
		if (file.eof()) {
			break;
		}
		cout << line << endl;
	}
	file.close();
}


void map_menu(Player& player) {
	if (player.in_battle) {
		return;
	}
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/map.txt");

		int input = _getch();
		switch (input) {
		case 4: // 1
			cout << 1 << endl;
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
		cout << "XP: " << player.get_xp() << " MONEY: " <<
			player.get_money() << endl;

		Weapon weapon = player.get_weapon();
		cout << "Оружие: \n";
		cout << weapon.name << endl << weapon.rare << endl << weapon.description;
		weapon.cost;
		int input = _getch();
		switch (input) {
		case 113: // Q
			save(player);
			menu_is_on = false;
			break;
		}
		cls();
	}
}


void txt_message_skills(string filename, int (&skills)[SKILLS_COUNT]) {
	ifstream file(filename, ios::in);
	int i = 0;
	while (true) {
		string line;
		getline(file, line);
		if (file.eof()) {
			break;
		}
		cout << line << skills[i] << endl;
		i++;
	}
	file.close();
}


int skill_points_menu(int(&skills)[5], int points) {
	bool menu_is_on = true;
	while (points > 0 && menu_is_on) {
		cls();
		cout << "Вам доступно " << points << " очков умений\n";
		cout << "Чтобы распределить их нажмите:\n";
		txt_message_skills("txt/skill_menu.txt", skills);

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
