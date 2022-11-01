#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "items_list.h"
#include "itemsdrop.h"
using namespace std;


class Location {
public:
	string name;
	string description;

	Enemy get_enemy() {
		return enemies[
			random(0, enemies.size())
		];
	}

	Enemy get_boss() {
		return bosses[
			random(0, bosses.size())
		];
	}

	Item get_random_item() {
		string rarity = get_random_rarity();
		return items[rarity][
			random(0, items[rarity].size())
		];
	}

	Item get_random_legendary_item() {
		string rarity = "legendary";
		return items[rarity][
			random(0, items[rarity].size())
		];
	}

protected:
	vector <Enemy> enemies;
	vector <Enemy> bosses;
	map <string, vector <Item>> items = {
		{"default", vector <Item> ()},
		{"rare", vector <Item> ()},
		{"epic", vector <Item> ()},
		{"legendary", vector <Item> ()},
	};
};


class NoLocation : public Location {
public:
	NoLocation() {
		name = "";
		description = "";
	};
};


class Forest : public Location {
public:
	Forest() {
		// class varibals reconstruct
		enemies = self_enemies;
		bosses = self_bosses;
		items = self_items;
		name = "Лес";
		description = "Темный таинственный лес";
	};

private:
	vector <Enemy> self_enemies{
		Slime,
		Skeleton,
		Box,
		ForestMonster,
		MiracleLight,
		Spider,
		Troll,
		Ghost,
		Kozel,
		Chest
	};

	vector <Enemy> self_bosses {
		Revenant,
	};

	map <string, vector <Item>> self_items = {
		{"default", 
			vector <Item> {
				Stick, Bow, // weapon
				Pot, // helm
				Jacket, LeatherJacket, // chestplate
				Pants, Kilt, // leggings
				Shoes // boots
			}},
		{"rare",
			vector <Item> {
				BerserkSword, // weapon
				DovakinsHelm, // helm
				MagicCape, // chestplate
				IronLeggings, // leggings
				TacticBoots // boots
			}},
		{"epic", 
			vector <Item> {
				BerserkSword, // weapon
				Kasa, // helm
				ChainmailPlate, // chestplate
				ScalyLegArmor, // leggings
				ReinforcedBoots //boots
			}},
		{"legendary",
			vector <Item> {
				WayfinderCrossbow, // weapon
				AzeriteHelm // helm
			}},
	};

};


// weapon
				// helm
				// chestplate
				// leggings
				//boots

