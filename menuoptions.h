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
			break;
		case 5: // 2
			break;
		case 6: // 3
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
		Helmet helmet = player.get_helmet();
		Chestplate chestplate = player.get_chestplate();
		Leggings leggings = player.get_leggings();
		Boots boots = player.get_boots();

		cout << "Оружие: \n";
		cout << "----------------------\n";
		cout << weapon.name << endl << weapon.rare << "\n\n" << weapon.description << endl;
		cout << "----------------------\n";
		cout << helmet.name << endl << helmet.rare << "\n\n" << helmet.description << endl;
		cout << "----------------------\n";
		cout << chestplate.name << endl << chestplate.rare << endl << chestplate.description << endl;
		cout << "----------------------\n";
		cout << leggings.name << endl << leggings.rare << "\n\n" << leggings.description << endl;
		cout << "----------------------\n";
		cout << boots.name << endl << boots.rare << "\n\n" << boots.description << endl;
		cout << "----------------------\n";

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
