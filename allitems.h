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
// boots - 8


// Legendary Items
Weapon LichsSword = Weapon(
    2, 1250, // id cost
    380, // damage
    "legendary", // rare
    "������� ������", // name 
    "������, ��� ��������� ���� �������, ������� ������ ������. ������� ���� ��� ������ ��������� �����, ���� ������� ����"
); //


Weapon WayfinderCrossbow = Weapon(
    3, 1337, // id cost
    320, // damage
    "legendary", // rare
    "������� ������������", // name 
    "��� ������ ������ �������� �������� ��� ������, ���� �����"
); //


Helmet HelmOfDomination = Helmet(
    2, 1340, // id cost
    20, 1, 25, // protection regeneration damage_boost
    "legendary", // rare
    "���� ����������", // name
    "��� ������ � ����� ���������� �������� ��������� �������"
);  //


Helmet AzeriteHelm = Helmet(
    3, 850, // id cost
    35, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "���������� ����", // name
    "����� ������ �������, ������� ����� ��������� ��������� �������. ������ ������ �������� ��� �� ����"
); //


Chestplate Mantle = Chestplate(
    2, 1100, // id cost
    20, 40, 0, // protection regeneration damage_boost
    "legendary", // rare
    "������ �����'�����, ������ ���������", // name
    "��� ��� ��������� ��� ������� �������� � �������, �����������������"
); //


Chestplate DiamondChestplate = Chestplate(
    3, 1570, // id cost
    45, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "�������� ���������", // name
    "����� ���� - �������� ������"
); //


Leggings PiercingLeggings = Leggings(
    2, 1111, // id cost
    17, 0, 15, // protection regeneration damage_boost
    "legendary", // rare
    "������� ������", // name
    "������ ��������� �������� ��������, ������� �� �� �����"
); //


Leggings Bloomers = Leggings(
    3, 960, // id cost
    15, 9, 2, // protection regeneration damage_boost
    "legendary", // rare
    "��������", // name
    "������ ������� - ������ ��������"
); // 


Boots BootsOfRebirth = Boots(
    2, 670, // id cost
    35, 2, 15, // protection regeneration damage_boost
    "legendary", // rare
    "������ ������������", // name
    "����� ��� - ����� �������, ��� �� ��� �����?"
); //


Boots LucifersBerets = Boots(
    3, 666, // id cost
    6, 6, 6, // protection regeneration damage_boost
    "legendary", // rare
    "����� ���� �������� ������", // name
    "����� ������������ ������ �.�. ������, � ��� ���� ���-�� ����������"
); //


// Items --------------------------------------------------------------------------------
Weapon Punch = Weapon(
    0, 0, // id cost
    15, // damage
    "default", // rare
    "������", // name 
    "������� ������, ���� � ������� ��������\n������ ���� - ������ ������"
); //


Weapon Stick = Weapon(
    4, 10, // id cost
    20, // damage
    "default", // rare
    "�����", // name 
    "������� � ����������"
); //


Weapon Bow = Weapon(
    5, 100, // id cost
    45, // damage
    "rare", // rare
    "���", // name 
    "������ ����� - ����� �� ����������"
); //


Weapon BerserkSword = Weapon(
    6, 450, // id cost
    140, // damage
    "epic", // rare
    "��� ��������", // name 
    "����������� ������� � ������ ������ � �������� ��������� �� ���� ����� ��������� ���������� ������� � ������ ��������"
); //


Helmet Hat = Helmet(
    1, 35,  // id cost
    2, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�����", // name
    ""
); //


Helmet Pot = Helmet(
    4, 35, // id cost
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "��������", // name
    ""
); //


Helmet DovakinsHelm = Helmet(
    5, 100, // id cost
    7, 2, 3, // protection regeneration damage_boost
    "rare", // rare
    "���� ��������", // name
    "�����-�� ��� ����� ����������������"
); //


Helmet Kasa = Helmet(
    6, 450, // id cost
    15, 1, 3, // protection regeneration damage_boost
    "epic", // rare
    "�������� ���� ������", // name
    "�������, �������� ������� ����� ���, ��� ������� ������ ����� ������������"
); //


Chestplate Jacket = Chestplate(
    1, 40, // id cost
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    "��������� ������"
); //


Chestplate LeatherJacket = Chestplate(
    4, 50, // id cost
    6, 0, 2, // protection regeneration damage_boost
    "default", // rare
    "�������", // name
    "����� �� ��� � � �-800"
); //


Chestplate MagicCape = Chestplate(
    5, 85, // id cost
    15, 2, 1, // protection regeneration damage_boost
    "rare", // rare
    "���������� �������", // name
    "�� ��� ������� �������������� ����"
); //


Chestplate ChainmailPlate = Chestplate(
    6, 800, // id cost
    25, 0, 4, // protection regeneration damage_boost
    "epic", // rare
    "���������� ���������", // name
    "��� ������ � ������� �� �������"
); //


Leggings Pants = Leggings(
    1, 45, // id cost
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "������", // name
    "���� ���������"
); //


Leggings Kilt = Leggings(
    4, 55, // id cost
    5, 0, 1, // protection regeneration damage_boost
    "default", // rare
    "����", // name
    "�� ����"
); //


Leggings IronLeggings = Leggings(
    5, 80, // id cost
    10, 0, 1, // protection regeneration damage_boost
    "rare", // rare
    "�������� ������", // name
    "������ � �������� ��������� ���������"
); //


Leggings ScalyLegArmor = Leggings(
    6, 700, // id cost
    20, 4, 4, // protection regeneration damage_boost
    "epic", // rare
    "���������� ������ ����", // name
    "���������� ��������� �����"
); //


Boots Shoes = Boots(
    1, 40, // id cost
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�������", // name
    ""
); //


Boots Slippers = Boots(
    4, 40, // id cost
    5, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "�����", // name
    "� ��� ������..."
); //


Boots TacticBoots = Boots(
    5, 40, // id cost
    10, 1, 1, // protection regeneration damage_boost
    "rare", // rare
    "����������� �������", // name
    "� ��� ������ ����������� ���"
); //


Boots ElectricBoots = Boots(
    6, 220, // id cost
    14, 0, 7, // protection regeneration damage_boost
    "epic", // rare
    "������� �������", // name
    "����� �� �� �������"
); //


Boots ReinforcedBoots = Boots(
    7, 200, // id cost
    18, 0, 2, // protection regeneration damage_boost
    "epic", // rare
    "��������� ��������", // name
    "������� ������ �����"
); //


// NoItems
Weapon NoWeapon = Punch;


Helmet NoHelmet = Helmet(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Chestplate NoChestplate = Chestplate(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Leggings NoLeggings = Leggings(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);


Boots NoBoots = Boots(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "������", // name 
    ""
);



#endif
