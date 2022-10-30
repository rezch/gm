#ifndef ALLITEMS_h
#define ALLITEMS_h
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


// weapons - 7
// helmets - 7
// chestplates - 7
// leggings - 7
// boots - 7


// Legendary Items
Weapon LichsSword = Weapon(
    2, 1250, 0, // id cost weight
    340, // damage
    "legendary", // rare
    "������� ������", // name 
    "������, ��� ��������� ���� �������, ������� ������ ������. ������� ���� ��� ������ ��������� �����, ���� ������� ����"
); //


Weapon WayfinderCrossbow = Weapon(
    3, 1337, 0, // id cost weight
    350, // damage
    "legendary", // rare
    "������� ������������", // name 
    "��� ������ ������ �������� �������� ��� ������, ���� �����"
); //


Helmet HelmOfDomination = Helmet(
    2, 1340, 0,  // id cost weight
    20, 1, 25, // protection regeneration damage_boost
    "legendary", // rare
    "���� ����������", // name
    "��� ������ � ����� ���������� �������� ��������� �������"
);  //


Helmet AzeriteHelm = Helmet(
    3, 850, 0,  // id cost weight
    35, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "���������� ����", // name
    "����� ������ �������, ������� ����� ��������� ��������� �������. ������ ������ �������� ��� �� ����"
); //


Chestplate Mantle = Chestplate(
    2, 1100, 0,  // id cost weight
    20, 40, 0, // protection regeneration damage_boost
    "legendary", // rare
    "������ �����'�����, ������ ���������", // name
    "��� ��� ��������� ��� ������� �������� � �������, �����������������"
); //


Chestplate DiamondChestplate = Chestplate(
    3, 1570, 0, // id cost weight
    45, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "�������� ���������", // name
    "����� ���� - �������� ������"
); //


Leggings PiercingLeggings = Leggings(
    2, 1111, 0,  // id cost weight
    17, 0, 15, // protection regeneration damage_boost
    "legendary", // rare
    "������� ������", // name
    "������ ��������� �������� ��������, ������� �� �� �����"
); //


Leggings Bloomers = Leggings(
    3, 960, 0,  // id cost weight
    15, 9, 2, // protection regeneration damage_boost
    "legendary", // rare
    "��������", // name
    "������ ������� - ������ ��������"
); // 


Boots BootsOfRebirth = Boots(
    2, 670, 0,  // id cost weight
    35, 2, 15, // protection regeneration damage_boost
    "legendary", // rare
    "������ ������������", // name
    "����� ��� - ����� �������, ��� �� ��� �����?"
); //


Boots LucifersBerets = Boots(
    3, 666, 0,  // id cost weight
    6, 6, 6, // protection regeneration damage_boost
    "legendary", // rare
    "����� ���� �������� ������", // name
    "����� ������������ ������ �.�. ������, � ��� ���� ���-�� ����������"
); //


// Items --------------------------------------------------------------------------------
Weapon Punch = Weapon(
    1, 0, 0, // id cost weight
    15, // damage
    "default", // rare
    "������", // name 
    "������� ������, ���� � ������� ��������\n������ ���� - ������ ������"
); //


Weapon Stick = Weapon(
    4, 10, 0, // id cost weight
    20, // damage
    "default", // rare
    "�����", // name 
    "������� � ����������"
); //


Weapon Bow = Weapon(
    5, 100, 0, // id cost weight
    45, // damage
    "rare", // rare
    "���", // name 
    "������ ����� - ����� �� ����������"
); //


Weapon BerserkSword = Weapon(
    6, 450, 0, // id cost weight
    140, // damage
    "epic", // rare
    "��� ��������", // name 
    "����������� ������� � ������ ������ � �������� ��������� �� ���� ����� ��������� ���������� ������� � ������ ��������"
); //


Helmet Hat = Helmet(
    1, 35, 0,  // id cost weight
    2, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�����", // name
    ""
); //


Helmet Pot = Helmet(
    4, 35, 0,  // id cost weight
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "��������", // name
    ""
); //


Helmet DovakinsHelm = Helmet(
    5, 100, 0,  // id cost weight
    7, 2, 3, // protection regeneration damage_boost
    "rare", // rare
    "���� ��������", // name
    "�����-�� ��� ����� ����������������"
); //


Helmet Kasa = Helmet(
    6, 450, 0,  // id cost weight
    15, 1, 3, // protection regeneration damage_boost
    "epic", // rare
    "�������� ���� ������", // name
    "�������, �������� ������� ����� ���, ��� ������� ������ ����� ������������"
); //


Chestplate Jacket = Chestplate(
    1, 40, 0,  // id cost weight
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    "��������� ������"
); //


Chestplate LeatherJacket = Chestplate(
    4, 50, 0,  // id cost weight
    6, 0, 2, // protection regeneration damage_boost
    "default", // rare
    "�������", // name
    "����� �� ��� � � �-800"
); //


Chestplate MagicCape = Chestplate(
    5, 85, 0,  // id cost weight
    15, 2, 1, // protection regeneration damage_boost
    "rare", // rare
    "���������� �������", // name
    "�� ��� ������� �������������� ����"
); //


Chestplate ChainmailPlate = Chestplate(
    6, 800, 0,  // id cost weight
    25, 0, 4, // protection regeneration damage_boost
    "epic", // rare
    "���������� ���������", // name
    "��� ������ � ������� �� �������"
); //


Leggings Pants = Leggings(
    1, 45, 0,  // id cost weight
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    "���� ���������"
); //


Leggings Kilt = Leggings(
    4, 55, 0,  // id cost weight
    5, 0, 1, // protection regeneration damage_boost
    "default", // rare
    "����", // name
    "�� ����"
); //


Leggings IronLeggings = Leggings(
    5, 80, 0,  // id cost weight
    10, 0, 1, // protection regeneration damage_boost
    "rare", // rare
    "�������� ������", // name
    "������ � �������� ��������� ���������"
); //


Leggings ScalyLegArmor = Leggings(
    6, 700, 0,  // id cost weight
    20, 4, 4, // protection regeneration damage_boost
    "epic", // rare
    "���������� ������ ����", // name
    "���������� ��������� �����"
); //


Boots Shoes = Boots(
    1, 40, 0,  // id cost weight
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�������", // name
    ""
); //


Boots Slippers = Boots(
    4, 40, 0,  // id cost weight
    5, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�����", // name
    "� ��� ������..."
); //


Boots TacticBoots = Boots(
    5, 40, 0,  // id cost weight
    10, 1, 1, // protection regeneration damage_boost
    "rare", // rare
    "����������� �������", // name
    "� ��� ������ ����������� ���"
); //


Boots ElectricBoots = Boots(
    6, 220, 0,  // id cost weight
    14, 0, 7, // protection regeneration damage_boost
    "epic", // rare
    "������� �������", // name
    "����� �� �� �������"
); //


// NoItems
Weapon NoWeapon = Punch;


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



#endif
