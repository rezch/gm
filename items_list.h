#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


Weapon Punch = Weapon(
    0, 0, 0, // id cost weight
    15, // damage
    "default", // rare
    "Кулаки", // name 
    "обычные кулаки, есть у каждого человека\nБольше силы - больше пользы"
);


Helmet Hat = Helmet(
    1, 5, 0,  // id cost weight
    2, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Шляпа", // name
    ""
);


Chestplate Jacket = Chestplate(
    2, 5, 0,  // id cost weight
    5, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Куртка", // name
    ""
);


Leggings Pants = Leggings(
    3, 4, 0,  // id cost weight
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Джинсы", // name
    ""
);


Boots Shoes = Boots(
    4, 4, 0,  // id cost weight
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Ботинки", // name
    ""
);



map <int, Weapon> weapons_list = {
    {0, Punch},
};


map <int, Helmet> helmets_list = {
    {1, Hat},
};


map <int, Chestplate> chestplate_list = {
    {2, Jacket},
};


map <int, Leggings> leggings_list = {
    {3, Pants},
};


map <int, Boots> boots_list = {
    {4, Shoes},
};


#endif
