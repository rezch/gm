#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "trader.h"
#include "locations.h"
using namespace std;


void forest_menu(Player& player, Location& location) {
	while (true) {
		cls();
		txt_message("locations/forest.txt");

		int input = _getch();
		switch (input) {
		case 49: // 1
			arena_menu(player, location);
			break;
		case 50: // 2
			boss_menu(player, location);
			break;
		case 113: // Q
			return;
		}
	}
}


void map_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/map.txt");

		int input = _getch();
		switch (input) {
		case 49: // 1
			trader_menu(player);
			break;
		case 50: // 2
			forest_menu(player, (Location&)Forest());
			break;
		case 113: // Q
			save(player);
			menu_is_on = false;
			break;
		}
		cls();
	}
}

