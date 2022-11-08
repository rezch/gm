#ifndef ITEMSDROP_H
#define ITEMSDROP_H
#include <iostream>
#include <string>
#include <map>
#include "items_list.h"
using namespace std;


map <int, string> totype = {
	{0, "weapon"},
	{1, "helmet"},
	{2, "chestplate"},
	{3, "leggings"},
	{4, "boots"},
};


map <int, string> to_rarity = {
	{0, "default"},
	{1, "rare"},
	{2, "epic"},
	{3, "legendary"},
};


string get_random_rarity() {
	/* default   - 65 %
	*  rare      - 25 %
	*  epic      - 9 %
	*  legendary - 1 %
	*/
	int random_rarity = random(1, 101);
	if (random_rarity == 1) return to_rarity[3];
	if (random_rarity < 11) return to_rarity[2];
	if (random_rarity < 36) return to_rarity[1];
	return to_rarity[0];
}


int get_random_weapon_id() {
	return default_weapons_list[random(0, default_weapons_list.size())].id;
}


int get_random_helmet_id() {
	return default_helmets_list[random(0, default_helmets_list.size())].id;
}


int get_random_chestplate_id() {
	return default_chestplate_list[random(0, default_chestplate_list.size())].id;
}


int get_random_leggings_id() {
	return default_leggings_list[random(0, default_leggings_list.size())].id;
}


int get_random_boots_id() {
	return default_boots_list[random(0, default_boots_list.size())].id;
}


// Legendary Items
int get_random_legendary_weapon_id() {
	return legendary_weapons_list[random(0, legendary_weapons_list.size())].id;
}


int get_random_legendary_helmet_id() {
	return legendary_helmets_list[random(0, legendary_helmets_list.size())].id;
}


int get_random_legendary_chestplate_id() {
	return legendary_chestplate_list[random(0, legendary_chestplate_list.size())].id;
}


int get_random_legendary_leggings_id() {
	return legendary_leggings_list[random(0, legendary_leggings_list.size())].id;
}


int get_random_legendary_boots_id() {
	return legendary_boots_list[random(0, legendary_boots_list.size())].id;
}


// Get functions
pair <int, int> get_random_legendary_item_id() {
	int type = random(0, 1);
	int id = 0;
	switch (type) {
	case 0:
		id = get_random_legendary_weapon_id();
		break;
	case 1:
		id = get_random_legendary_helmet_id();
		break;
	case 2:
		id = get_random_legendary_chestplate_id();
		break;
	case 3:
		id = get_random_legendary_leggings_id();
		break;
	case 4:
		id = get_random_legendary_boots_id();
		break;
	}
	return make_pair(type, id);
}


pair <int, int> get_random_item_id() {
	if (random(0, 100) == 88) {
		return get_random_legendary_item_id();
	}
	int type = random(0, 5);
	int id = 0;
	switch (type) {
	case 0:
		id = get_random_weapon_id();
		break;
	case 1:
		id = get_random_helmet_id();
		break;
	case 2:
		id = get_random_chestplate_id();
		break;
	case 3:
		id = get_random_leggings_id();
		break;
	case 4:
		id = get_random_boots_id();
		break;
	}
	return make_pair(type, id);
}


template <typename Type>
void dropped_item_print(Player& player, Type& item) {
	const type_info& type = typeid(item);
	cls();

	cout << "Вам выпал предмет:\n" << type.name() << "\n";
	if (is_same<Type, Weapon>::value) {
		weapon_print((Weapon&)item, player, (Weapon&)player.get_weapon());
	}
	else {
		armor_compare((Armor&)item, (Armor&)player.get_item(item));
	}
}


template <typename Type>
void player_set_item(Player& player, Type& item) {
	player.set_item(item);
}


template <typename Type>
void dropped_item_choose(Player& player, Type& item) {
	while (true) {
		dropped_item_print(player, item);
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
		case 121: // Y
			if (player.trader_save) {
				player.add_money(item.cost);
				player.trader_save = false;
			}
			player_set_item(player, item);
			save(player);
			return;
		case 110: // N
			return;
		}
	}
}


#endif
