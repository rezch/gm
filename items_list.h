#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


Weapon NoWeapon = Weapon(
    0, 0, 0, // id cost weight
    0, // damage
    "default", // rare
    "������", // name 
    ""
);


Helmet NoHelmet = Helmet(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Chestplate NoChestplate = Chestplate(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Leggings NoLeggings = Leggings(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Boots NoBoots = Boots(
    0, 0, 0, // id cost weight
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Weapon Punch = Weapon(
    1, 0, 0, // id cost weight
    15, // damage
    "default", // rare
    "������", // name 
    "������� ������, ���� � ������� ��������\n������ ���� - ������ ������"
);


Helmet Hat = Helmet(
    1, 5, 0,  // id cost weight
    2, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�����", // name
    ""
);


Chestplate Jacket = Chestplate(
    1, 5, 0,  // id cost weight
    5, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    ""
);


Leggings Pants = Leggings(
    1, 4, 0,  // id cost weight
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    ""
);


Boots Shoes = Boots(
    1, 4, 0,  // id cost weight
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�������", // name
    ""
);



map <int, Weapon> weapons_list = {
    {0, NoWeapon},
    {1, Punch},
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


#endif
