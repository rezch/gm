#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;


const short int cyan = 3;
const short int green = 2;
const short int purple = 5;
const short int yellow = 6;
const short int red = 4;
const short int red_font = 64;
const short int yellow_font = 96;

const short int hp_color = red;
const short int xp_color = green;
const short int cost_color = yellow;
const short int armor_color = cyan;
const short int weapon_color = cyan;
const short int armor_properties = green;
const short int weapon_properties = red;
const short int skill_points_color = cyan;


void cls() {
	system("cls");
}


void ccout(string text, int color, bool endline) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	if (endline) {
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
}


void dout(int a, int b) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (a < b) {
		SetConsoleTextAttribute(hConsole, 4);
		cout << '(' << a - b << ')';
	}
	else {
		SetConsoleTextAttribute(hConsole, 2);
		cout << "(+" << a - b << ')';
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n";
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


void txt_message_skills(string filename, int(&skills)[SKILLS_COUNT]) {
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


void player_info_print(Player& player) {
	ccout("SKILL POINTS:", skill_points_color, 0);
	cout << " " << player.get_skillpoints() << "\n";
	ccout("HP:", hp_color, 0);
	cout << " " << player.get_hp() << " / " << player.get_full_hp() << "\n";
	ccout("XP:", xp_color, 0);
	cout << " " << player.get_xp() << "\n";
	ccout("MONEY:", cost_color, 0);
	cout << " " << player.get_money() << "\n\n";
}


void weapon_print(Weapon& weapon, Player& player) {
	ccout(weapon.name, rarity[weapon.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << weapon.cost << "\n";
	ccout("     Урон:", weapon_properties, 0);
	cout << " " << weapon.damage + player.weapon_upg << "\n";
	cout << weapon.description << "\n";
}


void armor_print(Armor& armor, Player& player) {
	ccout(armor.name, rarity[armor.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << armor.cost << "\n";

	ccout("             Защита:", armor_properties, 0);
	cout << " " << armor.protection + player.helmet_upg << "\n";

	ccout("        Регенерация:", armor_properties, 0);
	cout << " " << armor.regeneration << "\n";

	ccout("Дополнительный урон:", armor_properties, 0);
	cout << " " << armor.damage_boost << "\n";
	cout << armor.description << "\n";
}


void player_items_print(Player& player) {
	// Weapon
	Weapon weapon = player.get_weapon();
	ccout("Оружие: ", weapon_color, 1);
	cout << "[1] ";
	weapon_print(weapon, player);

	// Armor
	ccout("\nБроня: ", armor_color, 1);
	Armor player_armor_list[4] = {
		player.get_helmet(),
		player.get_chestplate(),
		player.get_leggings(),
		player.get_boots()
	};

	for (int i = 0; i < 4; i++) {
		cout << '[' << i + 2 << ']' << endl;
		armor_print(player_armor_list[i], player);
	}
}


void items_upgrade_print(Player& player) {
	player_info_print(player);
	ccout("Стоимость улучшения:", cost_color, 0);
	cout << " " << player.item_updrade_cost << "\n\n";
	
	Item player_items_list[5] = {
		player.get_weapon(),
		player.get_helmet(),
		player.get_chestplate(),
		player.get_leggings(),
		player.get_boots()
	};

	for (int i = 0; i < 5; i++) {
		cout << '[' << i + 1 << ']' << endl;
		ccout(player_items_list[i].name, rarity[player_items_list[i].rare], 1);
	}
}


#endif
