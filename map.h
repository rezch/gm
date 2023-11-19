#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "trader.h"
#include "pve.h"
using namespace std;


void forest_menu(Player& player) {
	while (true) {
		cls();
		txt_message("locations/forest.txt");

		switch (_getch()) {
            case 49: // 1
                arena_menu(player, Locations::Forest);
                return;
            case 50: // 2
                boss_menu(player, Locations::Forest);
                return;
            case 113: // Q
                return;
            default:
                break;
		}
	}
}


void map_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/map.txt");

		switch (_getch()) {
            case 49: // 1
                trader_menu(player);
                break;
            case 50: // 2
                forest_menu(player);
                break;
            case 113: // Q
                save(player);
                menu_is_on = false;
                break;
            default:
                break;
		}
		cls();
	}
}

