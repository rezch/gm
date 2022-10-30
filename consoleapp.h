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
const short int weapon_color = cyan;
const short int armor_color = cyan;
const short int cost_color = yellow;
const short int weapon_properties = red;
const short int armor_properties = green;


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


void player_items_print(Player& player) {
	ccout("MONEY:", 6, 0);
	cout << " " << player.get_money() << "\n\n";

	Weapon weapon = player.get_weapon();
	Helmet helmet = player.get_helmet();
	Chestplate chestplate = player.get_chestplate();
	Leggings leggings = player.get_leggings();
	Boots boots = player.get_boots();

	// Weapon
	ccout("Оружие: ", weapon_color, 1);
	cout << "[1] ";
	ccout(weapon.name, rarity[weapon.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << weapon.cost << "\n";
	ccout("     Урон:", weapon_properties, 0);
	cout << " " << weapon.damage + player.weapon_upg << "\n";
	cout << weapon.description << "\n";

	ccout("\nБроня: ", armor_color, 1);
	// Helmet
	cout << "\n[2] ";
	ccout(helmet.name, rarity[helmet.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << helmet.cost << "\n";

	ccout("             Защита:", armor_properties, 0);
	cout << " " << helmet.protection + player.helmet_upg << "\n";

	ccout("        Регенерация:", armor_properties, 0);
	cout << " " << helmet.regeneration << "\n";

	ccout("Дополнительный урон:", armor_properties, 0);
	cout << " " << helmet.damage_boost << "\n";
	cout << helmet.description << "\n";

	// Chestplate
	cout << "\n[3] ";
	ccout(chestplate.name, rarity[chestplate.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << chestplate.cost << "\n";

	ccout("             Защита:", armor_properties, 0);
	cout << " " << chestplate.protection + player.chestplate_upg << "\n";

	ccout("        Регенерация:", armor_properties, 0);
	cout << " " << chestplate.regeneration << "\n";

	ccout("Дополнительный урон:", armor_properties, 0);
	cout << " " << chestplate.damage_boost << "\n";
	cout << chestplate.description << "\n";

	// Leggings
	cout << "\n[4] ";
	ccout(leggings.name, rarity[leggings.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << leggings.cost << "\n";

	ccout("             Защита:", armor_properties, 0);
	cout << " " << leggings.protection + player.leggings_upg << "\n";

	ccout("        Регенерация:", armor_properties, 0);
	cout << " " << leggings.regeneration << "\n";

	ccout("Дополнительный урон:", armor_properties, 0);
	cout << " " << leggings.damage_boost << "\n";
	cout << leggings.description << "\n";

	// Boots
	cout << "\n[5] ";
	ccout(boots.name, rarity[boots.rare], 1);
	ccout("Стоимость:", cost_color, 0);
	cout << " " << boots.cost << "\n";

	ccout("             Защита:", armor_properties, 0);
	cout << " " << boots.protection + player.boots_upg << "\n";

	ccout("        Регенерация:", armor_properties, 0);
	cout << " " << boots.regeneration << "\n";

	ccout("Дополнительный урон:", armor_properties, 0);
	cout << " " << boots.damage_boost << "\n";
	cout << boots.description << "\n";
}


void items_upgrade_print(Player& player) {
	ccout("MONEY:", 6, 0);
	cout << " " << player.get_money() << "\n\n";
	ccout("Стоимость улучшения:", cost_color, 0);
	cout << " " << player.item_updrade_cost << "\n\n";

	Weapon weapon = player.get_weapon();
	Helmet helmet = player.get_helmet();
	Chestplate chestplate = player.get_chestplate();
	Leggings leggings = player.get_leggings();
	Boots boots = player.get_boots();

	// Weapon
	ccout("Оружие: ", weapon_color, 1);
	cout << "[1] ";
	ccout(weapon.name, rarity[weapon.rare], 1);

	ccout("\nБроня: ", armor_color, 1);
	// Helmet
	cout << "[2] ";
	ccout(helmet.name, rarity[helmet.rare], 1);

	// Chestplate
	cout << "[3] ";
	ccout(chestplate.name, rarity[chestplate.rare], 1);

	// Leggings
	cout << "[4] ";
	ccout(leggings.name, rarity[leggings.rare], 1);

	// Boots
	cout << "[5] ";
	ccout(boots.name, rarity[boots.rare], 1);
}


#endif
