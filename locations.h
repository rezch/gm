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

	vector <Enemy> enemies;
	vector <Enemy> bosses;
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
		name = "Лес";
		description = "Темный таинственный лес";
	};

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

};


// weapon
				// helm
				// chestplate
				// leggings
				//boots

