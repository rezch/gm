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


map <int, string> torarity = {
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
	int rarity = random(1, 101);
	if (rarity == 1) return torarity[3];
	if (rarity < 11) return torarity[2];
	if (rarity < 36) return torarity[1];
	return torarity[0];
}


void dropped_item_print(Player& player, Item item) {
	const type_info& type = typeid(item);
	cls();

	cout << "Вам выпал предмет:\n" << type.name() << "\n";
	if (type == typeid(Weapon)) {
		weapon_print((Weapon&)item, player, (Weapon&)player.get_weapon());
	}
	if (type == typeid(Helmet)) {
		armor_compare((Armor&)item, (Armor&)player.get_helmet());
	}
	if (type == typeid(Chestplate)) {
		armor_compare((Armor&)item, (Armor&)player.get_chestplate());
	}
	if (type == typeid(Leggings)) {
		armor_compare((Armor&)item, (Armor&)player.get_leggings());
	}
	if (type == typeid(Weapon)) {
		armor_compare((Armor&)item, (Armor&)player.get_boots());
	}
}


void player_set_item(Player& player, Item item) {
	const type_info& type = typeid(item);

	if (type == typeid(Weapon)) {
		return player.set_weapon(item.id);
	}
	if (type == typeid(Helmet)) {
		return player.set_helmet(item.id);
	}
	if (type == typeid(Chestplate)) {
		return player.set_chestplate(item.id);
	}
	if (type == typeid(Leggings)) {
		return player.set_leggings(item.id);
	}
	if (type == typeid(Boots)) {
		return player.set_boots(item.id);
	}
}


void dropped_item_choose(Player& player, Item item) {
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
