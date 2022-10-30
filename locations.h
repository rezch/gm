#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "items_list.h"
using namespace std;



class Location {
public:
	Location() {};

	string name;
	string description;



protected:
	vector <int> items;
	vector <Weapon> weapones;
	vector <Helmet> helmets;
	vector <Chestplate> chestplates;
	vector <Leggings> leggings;
	vector <Boots> boots;
};

