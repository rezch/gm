#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <vector>
#include <windows.h>
#include "consoleapp.h"
#include "pve.h"
#include "items_list.h"
using namespace std;


const float upgrade_cost_k = 1.25;


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
	cout << "[2] ";
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
	cout << "[3] ";
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
	cout << "[4] ";
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
	cout << "[5] ";
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


void buy_health_potion(Player& player) {
	if (player.get_money() >= helth_potion_cost) {
		while (true) {
			cls();
			txt_message("txt/potion_menu.txt");

			ccout("Ваше здоровье: ", hp_color, 0);
			cout << player.get_hp() << "\n";
			ccout("Ваши монеты: ", cost_color, 0);
			cout << player.get_money() << "\n";

			int input = _getch();
			switch (input) {
			case 49: // 1
				player.spend_money(helth_potion_cost);
				player.add_hp(helth_potion_regeneration);
				save(player);
				break;
			case 50: // 2
				return;
			case 130: // Q
				return;
			}
		}
	}
	else {
		cls();
		cout << "У вас недостаточно денег\n";
		_getch();
	}
}


void buy_trader_save(Player& player) {
	if (player.trader_save) {
		cls();
		cout << "Уже приобретено\n";
		int input = _getch();
		cls();
		return;
	}
	if (player.get_money() >= trader_save_cost) {
		while (true) {
			cls();
			txt_message("txt/buy_trader_save_menu.txt");

			ccout("Ваши монеты: ", cost_color, 0);
			cout << player.get_money() << "\n";

			int input = _getch();
			switch (input) {
			case 49: // 1
				player.spend_money(trader_save_cost);
				player.trader_save = true;
				save(player);
				return;
			case 50: // 2
				return;
			case 130: // Q
				return;
			}
		}
	}
	else {
		cls();
		cout << "У вас недостаточно денег\n";
		_getch();
	}
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
			buy_health_potion(player);
			break;
		case 52: // 4
			buy_trader_save(player);
			break;
		case 113: // Q
			save(player);
			menu_is_on = false;
			break;
		}
		cls();
	}
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
		Enemy enemy = get_enemy();
		switch (input) {
		case 49: // 1
			trader_menu(player);
			break;
		case 50: // 2
			arena_menu(player);
			break;
		case 51: // 3
			boss(player);
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
		ccout("HP:", 4, 0);
		cout << " " << player.get_hp() << " / " << player.get_full_hp() << "\n";
		ccout("XP:", 2, 0);
		cout << " " << player.get_xp() << "\n";
		player_items_print(player);

		int input = _getch();
		switch (input) {
		case 113: // Q
			save(player);
			return;
		}
		cls();
	}
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
