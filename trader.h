#pragma once
#include <iostream>
#include <string>
#include "consoleapp.h"
using namespace std;


const float upgrade_cost_k = 1.25;



void item_upgrade_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		if (player.get_money() > player.item_updrade_cost) {
			txt_message("txt/item_upgrade_menu.txt");
			items_upgrade_print(player);

			int input = _getch();
			switch (input) {
			case 49: // 1
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost *= upgrade_cost_k;
				player.weapon_upgrade();
				break;
			case 50: // 2
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost *= upgrade_cost_k;
				player.helmet_upgrade();
				break;
			case 51: // 3
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost *= upgrade_cost_k;
				player.chestplate_upgrade();
				break;
			case 52: // 4
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost *= upgrade_cost_k;
				player.leggings_upgrade();
				break;
			case 53: // 5
				player.spend_money(player.item_updrade_cost);
				player.item_updrade_cost *= upgrade_cost_k;
				player.boots_upgrade();
				break;
			case 113: // Q
				save(player);
				menu_is_on = false;
				break;
			}
			cls();
		}
		else {
			ccout("MONEY:", 96, 0);
			cout << " " << player.get_money() << "\n\n";
			ccout("Стоимость улучшения:", 96, 0);
			cout << " " << player.item_updrade_cost << "\n\n";
			cout << "У вас недостаточно денег" << "\n";

			int input = _getch();
			switch (input) {
			case 113: // Q
				menu_is_on = false;
				break;
			}
		}
	}
}


void sell_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		cout << "Выберите вещь на продажу\n";
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
		}
		cls();
	}
}


int trader_buy_menu(Player& player, int cost, void (*action)(Player& player), string txt_file) {
	while (player.get_money() >= cost) {
		cls();
		txt_message(txt_file);

		ccout("Ваши монеты: ", cost_color, 0);
		cout << player.get_money() << "\n";

		int input = _getch();
		switch (input) {
		case 49: // 1
			action(player);
			player.spend_money(cost);
			save(player);
			return 1;
		case 50: // 2
			return 0;
		case 113: // Q
			return 0;
		}
	}
	if (player.get_money() < cost) {
		cls();
		cout << "У вас недостаточно денег\n";
		_getch();
	}
}


void buy_health_potion(Player& player) {
	player.add_hp(helth_potion_regeneration);
}


void buy_trader_save(Player& player) {
	player.trader_save = true;
}


void trader_menu(Player& player) {
	bool menu_is_on = true;
	while (menu_is_on) {
		cls();
		txt_message("txt/trader.txt");
		int input = _getch();
		switch (input) {
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
				cout << "Уже приобретено\n";
				int input = _getch();
				cls();
				break;
			}
			trader_buy_menu(player, trader_save_cost, buy_trader_save, "txt/buy_trader_save_menu.txt");
			break;
		case 113: // Q
			save(player);
			menu_is_on = false;
			break;
		}
		cls();
	}
}