#ifndef PVE_H
#define PVE_H
#include <iostream>
#include <string>
#include "progress_save.h"
#include "enemies.h"
#include "consoleapp.h"
#include "itemsdrop.h"
using namespace std;




Enemy get_enemy() {
	return enemylist[random(0, enemy_count)];
}


Enemy get_boss() {
	return bosslist[random(0, boss_count)];
}


void info_print(Player& player, Enemy& enemy) {
	int player_hp_bar = 0;
	if (!player.is_dead()) {
		player_hp_bar = 10 * player.get_hp() / player.get_full_hp();
	}
	int enemy_hp_bar = 0;
	if (!enemy.is_dead()) {
		enemy_hp_bar = 10 * enemy.get_hp() / enemy.full_hp;
	}

	ccout("Ваш HP:", 160, 0);
	cout << " ";
	ccout(string(player_hp_bar, '*'), 160, 0);
	ccout(string(10 - player_hp_bar, '*'), 64, 0);
	cout << " (" << player.get_hp() << ')' << endl;
	cout << "\n";
	ccout(enemy.name + ':', 64, 0);
	cout << " ";
	ccout(string(enemy_hp_bar, '*'), 160, 0);
	ccout(string(10 - enemy_hp_bar, '*'), 64, 0);
	cout << " (" << enemy.get_hp() << ')' << endl;
}


int action_choose() {
	while (true) {
		int input = _getch();
		switch (input) {
		case 49: // 1
			return 1;
		case 50: // 2
			return 2;
		case 51: // 3
			return 3;
		}
	}
	return 0;
}


void dropped_item_print(Player& player, int type, int item_id) {
	cls();
	cout << "Вам выпал предмет:\n" << totype[type] << "\n";

	Weapon weapon;
	Helmet helmet;
	Chestplate chestplate;
	Leggings leggings;
	Boots boots;
	switch (type) {
	case 0: // Weapon
		weapon = weapons_list[item_id];
		ccout(weapon.name, rarity[weapon.rare], 1);
		ccout("Стоимость:", cost_color, 0);
		cout << " " << weapon.cost << " ";
		dout(weapon.cost, player.get_weapon().cost);

		ccout("     Урон:", weapon_properties, 0);
		cout << " " << weapon.damage << " ";
		dout(weapon.damage, player.get_weapon().damage);
		cout << weapon.description << "\n";
		break;
	case 1: // Helmet
		helmet = helmets_list[item_id];
		ccout(helmet.name, rarity[helmet.rare], 1);
		ccout("Стоимость:", cost_color, 0);
		cout << " " << helmet.cost << " ";
		dout(helmet.cost, player.get_helmet().cost);

		ccout("             Защита:", armor_properties, 0);
		cout << " " << helmet.protection << " ";
		dout(helmet.protection, player.get_helmet().protection);

		ccout("        Регенерация:", armor_properties, 0);
		cout << " " << helmet.regeneration << " ";
		dout(helmet.regeneration, player.get_helmet().regeneration);

		ccout("Дополнительный урон:", armor_properties, 0);
		cout << " " << helmet.damage_boost << " ";
		dout(helmet.damage_boost, player.get_helmet().damage_boost);
		cout << helmet.description << "\n";
		break;
	case 2: // Chestplate
		chestplate = chestplate_list[item_id];
		ccout(chestplate.name, rarity[chestplate.rare], 1);
		ccout("Стоимость:", cost_color, 0);
		cout << " " << chestplate.cost << " ";
		dout(chestplate.cost, player.get_helmet().cost);

		ccout("             Защита:", armor_properties, 0);
		cout << " " << chestplate.protection << " ";
		dout(chestplate.protection, player.get_helmet().protection);

		ccout("        Регенерация:", armor_properties, 0);
		cout << " " << chestplate.regeneration << " ";
		dout(chestplate.regeneration, player.get_helmet().regeneration);

		ccout("Дополнительный урон:", armor_properties, 0);
		cout << " " << chestplate.damage_boost << " ";
		dout(chestplate.damage_boost, player.get_helmet().damage_boost);
		cout << chestplate.description << "\n";
		break;
	case 3: // Leggings
		leggings = leggings_list[item_id];
		ccout(leggings.name, rarity[leggings.rare], 1);
		ccout("Стоимость:", cost_color, 0);
		cout << " " << leggings.cost << " ";
		dout(leggings.cost, player.get_helmet().cost);

		ccout("             Защита:", armor_properties, 0);
		cout << " " << leggings.protection << " ";
		dout(leggings.protection, player.get_helmet().protection);

		ccout("        Регенерация:", armor_properties, 0);
		cout << " " << leggings.regeneration << " ";
		dout(leggings.regeneration, player.get_helmet().regeneration);

		ccout("Дополнительный урон:", armor_properties, 0);
		cout << " " << leggings.damage_boost << " ";
		dout(leggings.damage_boost, player.get_helmet().damage_boost);
		cout << leggings.description << "\n";
		break;
	case 4: // Boots
		boots = boots_list[item_id];
		ccout(boots.name, rarity[boots.rare], 1);
		ccout("Стоимость:", cost_color, 0);
		cout << " " << boots.cost << " ";
		dout(boots.cost, player.get_helmet().cost);

		ccout("             Защита:", armor_properties, 0);
		cout << " " << boots.protection << " ";
		dout(boots.protection, player.get_helmet().protection);

		ccout("        Регенерация:", armor_properties, 0);
		cout << " " << boots.regeneration << " ";
		dout(boots.regeneration, player.get_helmet().regeneration);

		ccout("Дополнительный урон:", armor_properties, 0);
		cout << " " << boots.damage_boost << " ";
		dout(boots.damage_boost, player.get_helmet().damage_boost);
		cout << boots.description << "\n";
		break;
	}
}


void player_set_item(Player& player, int type, int id) {
	switch (type) {
	case 0:
		player.set_weapon(id);
		break;
	case 1:
		player.set_helmet(id);
		break;
	case 2:
		player.set_chestplate(id);
		break;
	case 3:
		player.set_leggings(id);
		break;
	case 4:
		player.set_boots(id);
		break;
	}
}


int player_item_cost(Player& player, int type) {
	switch (type) {
	case 0:
		return player.get_weapon().cost;
	case 1:
		return player.get_helmet().cost;
	case 2:
		return player.get_chestplate().cost;
	case 3:
		return player.get_leggings().cost;
	case 4:
		return player.get_boots().cost;
	}
}


void dropped_item_choose(Player& player, int type, int item_id) {
	while (true) {
		dropped_item_print(player, type, item_id);
		txt_message("txt/dropped_item_choose.txt");

		if (player.trader_save) {
			cout << "Ваш текущий предмет будет продан ";
			ccout("продан", green, 1);
		}
		else {
			cout << "Ваш текущий предмет будет ";
			ccout("утерян", red_font, 1);
		}

		int input = _getch();
		switch (input) {
		case 49: // 1
			if (player.trader_save) {
				player.add_money(player_item_cost(player, type));
			}
			player_set_item(player, type, item_id);
			save(player);
			return;
		case 50: // 2
			return;
		}
	}
}


void fight(Player& player, Enemy& enemy, bool is_boss) {
	player.in_battle = true;
	int last_hp = player.get_hp();

	cls();
	cout << "Вами был встречен ";
	ccout(enemy.name, 64, 1);
	cout << enemy.description << "\n";

	int input = _getch();
	cls();
	info_print(player, enemy);

	while (!enemy.is_dead() && !player.is_dead()) {
		txt_message("txt/attack_choose.txt");
		int action = action_choose();
		int player_attack = player.attack();
		int enemy_attack = enemy.attack();
		cls();
		switch (action) {
		case 1:
			enemy.take_damage(player_attack);
			player.take_damage(enemy_attack);
			cout << "Вы нанесли " << player_attack << " урона\n\n";
			cout << "Получен урон " << enemy_attack << "\n";
			info_print(player, enemy);
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	cls();
	if (!player.is_dead()) {
		if (is_boss) {
			pair <int, int> item = get_random_legendary_item_id();
			dropped_item_choose(player, item.first, item.second);
		}
		else {
			if (random(0, 101) >= 50) {
				pair <int, int> item = get_random_item_id();
				if (item.second != 0) {
					dropped_item_choose(player, item.first, item.second);
				}
			}
		}

		int points = random(0, 11) / 10;
		cout << "Вы получили:\n" << enemy.get_xp() << " опыта\n";
		cout << points << " очков умений\n";
		player.add_skillpoints(points);
		player.add_xp(enemy.get_xp());
		player.in_battle = false;
		save(player);
	}
	else {
		cout << "Вы проиграли...\n";
		player.add_hp(last_hp);
		player.in_battle = false;
	}
	input = _getch();
}


void arena_menu(Player& player) {
	bool menu_is_on = true;

	while (menu_is_on) {
		cls();
		cout << "Вы попали на арену смерти" << "\n";
		txt_message("txt/arena.txt");
		Enemy enemy = get_enemy();
		int input = _getch();
		switch (input) {
		case 49: // 1
			fight(player, enemy, 0);
			break;
		case 50: // 2
			menu_is_on = false;
			break;
		case 113: // Q
			menu_is_on = false;
			break;
		}
		cls();
	}
}


void boss(Player& player) {
	if (player.get_level() < 50) {
		cls();
		int points = 500 - player.get_xp();
		cout << "Ваш уровень ";
		ccout(to_string(player.get_level()), 2, 1);
		cout << "Вам необходимо получить еще " << points << " очков опыта, чтобы разблокировать боссов\n";
		int input = _getch();
		cls();
	}
	else {
		bool menu_is_on = true;

		while (menu_is_on) {
			cls();
			cout << "Блуждая по лесам, вы забрели в непонятное место, кажется скоро начнется битва" << "\n";
			txt_message("txt/arena.txt");
			Enemy enemy = get_boss();
			int input = _getch();
			switch (input) {
			case 49: // 1
				fight(player, enemy, 1);
				break;
			case 50: // 2
				menu_is_on = false;
				break;
			case 113: // Q
				menu_is_on = false;
				break;
			}
			cls();
		}
	}
}


#endif
