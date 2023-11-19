#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "creatures.h"

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


void ccout(const string& text, int color, bool end_line) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	if (end_line) {
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
}


template <class T>
void dout(const T& a, const T& b) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (a < b) {
		SetConsoleTextAttribute(hConsole, 4);
		cout << '(';
	}
	else {
		SetConsoleTextAttribute(hConsole, 2);
		cout << "(+";
	}
	cout << a - b << ')';
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n";
}


void txt_message(const string& filename) {
    ifstream file_input(filename);

    while (!file_input.eof()) {
        string line;
        getline(file_input, line);
        cout << line << endl;
    }
}


void txt_message_skills(const string& filename, int(&skills)[SKILLS_COUNT]) {
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
	ccout("SKILL POINTS:", skill_points_color, false);
	cout << " " << player.get_skillpoints() << "\n";
	ccout("HP:", hp_color, false);
	cout << " " << player.get_hp() << " / " << player.get_full_hp() << "\n";
	ccout("XP:", xp_color, false);
	cout << " " << player.get_xp() << "\n";
	ccout("MONEY:", cost_color, false);
	cout << " " << player.get_money() << "\n\n";
}


template <class T>
void weapon_print(Weapon& weapon, Player& player, T& second) {
	ccout(weapon.name, rarity[weapon.rare], true);
	ccout("Стоимость:", cost_color, false);
	cout << " " << weapon.cost << ' ';
	if (second.id != 0) dout(weapon.cost, second.cost);
	cout << "\n";
	ccout("     Урон:", weapon_properties, false);
	cout << " " << weapon.damage + player.weapon_upgrade_k << ' ';
	if (second.id != 0) {
        dout(weapon.damage, second.damage);
    }
	cout << "\n";
	cout << weapon.description << "\n";
}


float get_upgrades(Armor& armor, Player& player) {
	const type_info& type = typeid(armor);

	if (type == typeid(Helmet)) {
		return player.helmet_upgrade_k;
	}
	if (type == typeid(Chestplate)) {
		return player.chestplate_upgrade_k;
	}
	if (type == typeid(Leggings)) {
		return player.leggings_upgrade_k;
	}
	if (type == typeid(Boots)) {
		return player.boots_upgrade_k;
	}

    return 0;
}


void armor_print(Armor& armor, Player& player) {
	ccout(armor.name, rarity[armor.rare], true);
	ccout("Стоимость:", cost_color, false);
	cout << " " << armor.cost << "\n";
	ccout("             Защита:", armor_properties, false);
	cout << " " << armor.protection + get_upgrades(armor, player) << "\n";
	ccout("        Регенерация:", armor_properties, false);
	cout << " " << armor.regeneration << "\n";
	ccout("Дополнительный урон:", armor_properties, false);
	cout << " " << armor.damage_boost << "\n";
	cout << armor.description << "\n";
}


template <class T>
void armor_compare(Armor& armor, T& second) {
	ccout(armor.name, rarity[armor.rare], true);
	ccout("Стоимость:", cost_color, false);
	cout << " " << armor.cost << ' ';
	dout(armor.cost, second.cost);
	ccout("             Защита:", armor_properties, false);
	cout << " " << armor.protection << ' ';
	dout(armor.protection, second.protection);
	ccout("        Регенерация:", armor_properties, false);
	cout << " " << armor.regeneration << ' ';
	dout(armor.regeneration, second.regeneration);
	ccout("Дополнительный урон:", armor_properties, false);
	cout << " " << armor.damage_boost << ' ';
	dout(armor.damage_boost, second.damage_boost);
	cout << armor.description << "\n";
}


void player_items_print(Player& player) {
	// Weapon
	Weapon weapon = player.get_weapon();
	ccout("Оружие: ", weapon_color, true);
	cout << "[1] ";
	weapon_print(weapon, player, NoWeapon);

	// Armor
	ccout("\nБроня: ", armor_color, true);
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
	ccout("Стоимость улучшения:", cost_color, false);
	cout << " " << player.item_updrade_cost << "\n\n";
	
	pair <string, string> player_items_info[5] = {
            { player.get_weapon().name, player.get_weapon().rare },
            { player.get_helmet().name, player.get_helmet().rare },
            { player.get_chestplate().name, player.get_chestplate().rare },
            { player.get_leggings().name, player.get_leggings().rare },
            { player.get_boots().name, player.get_boots().rare },
	};

	for (int i = 0; i < 5; i++) {
		cout << '[' << i + 1 << ']' << endl;
		ccout(player_items_info[i].first, rarity[player_items_info[i].second], true);
	}
}


#endif
