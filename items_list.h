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
    "������",
    "������� ������, ���� � ������� ��������\n������ ���� - ������ ������"
);



const map <int, Weapon> weapones_list = {
    {0, Punch},
};

#endif