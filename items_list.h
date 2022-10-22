#ifndef ITEMS_LIST_H
#define ITEMS_LIST_H
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


Weapon Punch = Weapon(
    0,
    0,
    0,
    15,
    "default",
    "Кулаки",
    "обычные кулаки, есть у каждого человека\nБольше силы - больше пользы"
);



const map <int, Weapon> weapones_list = {
    {0, Punch},
};

#endif