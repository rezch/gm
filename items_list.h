#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H
#include <iostream>
#include <string>
#include "allitems.h"
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


// All items list (for game load) *******************************************************
map <int, Weapon> weapons_list = {
    {0, NoWeapon},
    {1, Punch},
    {2, LichsSword},
    {3, WayfinderCrossbow},
    {4, Stick},
    {5, Bow},
    {6, BerserkSword}
};


map <int, Helmet> helmets_list = {
    {0, NoHelmet},
    {1, Hat},
    {2, HelmOfDomination},
    {3, AzeriteHelm},
    {4, Pot},
    {5, DovakinsHelm},
    {6, Kasa},
};


map <int, Chestplate> chestplate_list = {
    {0, NoChestplate},
    {1, Jacket},
    {2, Mantle},
    {3, DiamondChestplate},
    {4, LeatherJacket},
    {5, MagicCape},
    {6, ChainmailPlate}
};


map <int, Leggings> leggings_list = {
    {0, NoLeggings},
    {1, Pants},
    {2, PiercingLeggings},
    {3, Bloomers},
    {4, Kilt},
    {5, IronLeggings},
    {6, ScalyLegArmor}
};


map <int, Boots> boots_list = {
    {0, NoBoots},
    {1, Shoes},
    {2, BootsOfRebirth},
    {3, LucifersBerets},
    {4, Slippers},
    {5, TacticBoots},
    {6, ElectricBoots}
};


// default - epic -----------------------------------------------------------------------
map <int, Weapon> default_weapons_list = {
    {0, NoWeapon},
    {1, Punch},
    {2, Stick},
    {3, Bow},
    {4, BerserkSword}
};


map <int, Helmet> default_helmets_list = {
    {0, NoHelmet},
    {1, Hat},
    {2, Pot},
    {3, DovakinsHelm},
    {4, Kasa},
};


map <int, Chestplate> default_chestplate_list = {
    {0, NoChestplate},
    {1, Jacket},
    {2, LeatherJacket},
    {3, MagicCape},
    {4, ChainmailPlate}
};


map <int, Leggings> default_leggings_list = {
    {0, NoLeggings},
    {1, Pants},
    {2, Kilt},
    {3, IronLeggings},
    {4, ScalyLegArmor}
};


map <int, Boots> default_boots_list = {
    {0, NoBoots},
    {1, Shoes},
    {2, Slippers},
    {3, TacticBoots},
    {4, ElectricBoots}
};


// Legendary Items ______________________________________________________________________
map <int, Weapon> legendary_weapons_list = {
    {0, LichsSword},
    {1, WayfinderCrossbow},
};


map <int, Helmet> legendary_helmets_list = {
    {0, HelmOfDomination},
    {1, AzeriteHelm}
};


map <int, Chestplate> legendary_chestplate_list = {
    {0, Mantle},
    {1, DiamondChestplate},
};


map <int, Leggings> legendary_leggings_list = {
    {0, PiercingLeggings},
    {1, Bloomers},
};


map <int, Boots> legendary_boots_list = {
    {0, BootsOfRebirth},
    {1, LucifersBerets},
};



#endif
