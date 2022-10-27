#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


int random(int from, int to) {
    srand(time(NULL));
    if (from > 0) return from + rand() % (to - from);
    else return from + rand() % (abs(from) + to);
}


map <string, int> rarity = {
    {"default", 15},
    {"rare", 11},
    {"epic", 13},
    {"legendary", 14},
};


// weapons - 3
// helmets - 2
// chestplates - 2
// leggings - 2
// boots - 2


// Legendary Items
Weapon LichsSword = Weapon(
    2, 1250, 0, // id cost weight
    340, // damage
    "legendary", // rare
    "Ледяная Скорбь", // name 
    "Всякий, кто завладеет этим клинком, получит вечную власть. Подобно тому как лезвие разрушает плоть, сила уродует душу"
);


// Items
Weapon Punch = Weapon(
    1, 0, 0, // id cost weight
    15, // damage
    "default", // rare
    "Кулаки", // name 
    "Обычные кулаки, есть у каждого человека\nБольше силы - больше пользы"
);


Helmet Hat = Helmet(
    1, 35, 0,  // id cost weight
    9, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Шляпа", // name
    ""
);


Chestplate Jacket = Chestplate(
    1, 50, 0,  // id cost weight
    15, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Куртка", // name
    ""
);


Leggings Pants = Leggings(
    1, 45, 0,  // id cost weight
    11, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Джинсы", // name
    ""
);


Boots Shoes = Boots(
    1, 40, 0,  // id cost weight
    7, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Ботинки", // name
    ""
);


// NoItems
Weapon NoWeapon = Punch;


Helmet NoHelmet = Helmet(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Chestplate NoChestplate = Chestplate(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Leggings NoLeggings = Leggings(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Boots NoBoots = Boots(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


// All items list (for game load)
map <int, Weapon> weapons_list = {
    {0, NoWeapon},
    {1, Punch},
    {2, LichsSword},
};


map <int, Helmet> helmets_list = {
    {0, NoHelmet},
    {1, Hat},
};


map <int, Chestplate> chestplate_list = {
    {0, NoChestplate},
    {1, Jacket},
};


map <int, Leggings> leggings_list = {
    {0, NoLeggings},
    {1, Pants},
};


map <int, Boots> boots_list = {
    {0, NoBoots},
    {1, Shoes},
};


// default - epic
map <int, Weapon> default_weapons_list = {
    {0, NoWeapon},
    {1, Punch},
};


map <int, Helmet> default_helmets_list = {
    {0, NoHelmet},
    {1, Hat},
};


map <int, Chestplate> default_chestplate_list = {
    {0, NoChestplate},
    {1, Jacket},
};


map <int, Leggings> default_leggings_list = {
    {0, NoLeggings},
    {1, Pants},
};


map <int, Boots> default_boots_list = {
    {0, NoBoots},
    {1, Shoes},
};


// Legendary Items
map <int, Weapon> legendary_weapons_list = {
    {0, LichsSword},
};


map <int, Helmet> legendary_helmets_list = {
    
};


map <int, Chestplate> legendary_chestplate_list = {
    
};


map <int, Leggings> legendary_leggings_list = {
    
};


map <int, Boots> legendary_boots_list = {
    
};



#endif
