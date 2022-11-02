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
