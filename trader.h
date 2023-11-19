#pragma once
#include <iostream>
#include <string>
#include "consoleapp.h"
using namespace std;


const float upgrade_cost_k = 1.25;


void item_upgrade_menu(Player& player) {
	while (true) {
		cls();
		if (player.get_money() > player.item_updrade_cost) {
			txt_message("txt/item_upgrade_menu.txt");
			items_upgrade_print(player);

			int input = _getch();
			if (input >= 1 && input <= 5) {
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost = (int)((float)player.item_updrade_cost * upgrade_cost_k);
			}
			switch (input) {
                case 49: // 1
                    player.weapon_upgrade();
                    break;
                case 50: // 2
                    player.helmet_upgrade();
                    break;
                case 51: // 3
                    player.chestplate_upgrade();
                    break;
                case 52: // 4
                    player.leggings_upgrade();
                    break;
                case 53: // 5
                    player.boots_upgrade();
                    break;
                case 113: // Q
                    save(player);
                    return;
                default:
                    break;
			}
			cls();
		}
		else {
			player_info_print(player);
			ccout("��������� ���������:", 96, false);
			cout << " " << player.item_updrade_cost << "\n\n";
			cout << "� ��� ������������ �����" << "\n";

            if (_getch() == 113) { // Q
                return;
            }
		}
	}
}


void sell_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		cout << "�������� ���� �� �������\n";
		player_items_print(player);

		int input = _getch();
		switch (input) {
            case 49: // 1
                player.add_money(player.get_weapon().cost);
                player.set_weapon(0);
                break;
            case 50: // 2
                player.add_money(player.get_helmet().cost);
                player.set_helmet(0);
                break;
            case 51: // 3
                player.add_money(player.get_chestplate().cost);
                player.set_chestplate(0);
                break;
            case 52: // 4
                player.add_money(player.get_leggings().cost);
                player.set_leggings(0);
                break;
            case 53: // 5
                player.add_money(player.get_boots().cost);
                player.set_boots(0);
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


int trader_buy_menu(Player& player, int cost, void (*action)(Player& player), const string& txt_file) {
	/*
	* returns 1 if the player successfully buys the item
	* returns 0 otherwise
	*/
	while (player.get_money() >= cost) {
		cls();
		txt_message(txt_file);
		player_info_print(player);

		int input = _getch();
		switch (input) {
            case 49: // 1
                action(player);
                save(player);
                return 1;
            case 50:
            case 113: // 2 | Q
                return 0;
            default:
                    break;
		}
	}
	if (player.get_money() < cost) {
		cls();
		cout << "� ��� ������������ �����\n";
		_getch();
	}
    return 0;
}


void buy_health_potion(Player& player) {
	if (player.get_hp() < player.get_full_hp()) {
		player.add_hp(helth_potion_regeneration);
		player.spend_money(helth_potion_cost);
	}
}


void buy_trader_save(Player& player) {
	player.trader_save = true;
	player.spend_money(trader_save_cost);
}


void trader_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/trader.txt");

		switch (_getch()) {
            case 49: // 1
                sell_menu(player);
                break;
            case 50: // 2
                item_upgrade_menu(player);
                break;
            case 51: // 3
                while (
                    trader_buy_menu(player, helth_potion_cost, buy_health_potion, "txt/potion_menu.txt")
                    ) continue;
                break;
            case 52: // 4
                if (player.trader_save) {
                    cls();
                    cout << "��� �����������\n";
                    _getch();
                    cls();
                    break;
                }
                trader_buy_menu(player, trader_save_cost, buy_trader_save, "txt/buy_trader_save_menu.txt");
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
