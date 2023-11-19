#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "creatures.h"
using namespace std;


const short int enemy_count = 10;
const short int boss_count = 6;


// Bosses

Enemy KingLichBoss = Enemy(
	"������ ���", // name
	"����� �� �������� �������� ������� ������, ����� ���� �������� ���������� �����", // description
	50, 35, 15, // damage resistance regeneration
	500, 1000 // hp xp
); //


Enemy MotherDemon = Enemy(
	"���� �������", // name
	"������� ��������� ���� ����, �� ���������� � �������� �", // description
	40, 20, 50, // damage resistance regeneration
	600, 1200 // hp xp
); //


Enemy Demon12 = Enemy(
	"����� 12 ���", // name
	"�������� ����������� ����� � ������������ � �����������", // description
	35, 15, 60, // damage resistance regeneration
	370, 1400 // hp xp
); //


Enemy Revenant = Enemy(
	"��������", // name
	"����� ����� ����� ������� ���� ����. ������� � ��� ��������", // description
	70, 20, 15, // damage resistance regeneration
	450, 1300 // hp xp
); //


Enemy MM = Enemy(
	"M&M", // name
	"...", // description
	60, 20, 20, // damage resistance regeneration
	666, 1500 // hp xp
); //


Enemy AdamSmasher = Enemy(
	"���� ������", // name
	"������. ������ �����. ����� �������, �� ����� �� �� ��������� ����", // description
	50, 20, 20, // damage resistance regeneration
	550, 1150 // hp xp
); //


// Default enemies ----------------------------------------------------------------------

Enemy Slime = Enemy(
	"�������", // name
	"��������� � ���������", // description
	10, 1, 3, // damage resistance regeneration
	40, 30 // hp xp
); //


Enemy Skeleton = Enemy(
	"������", // name
	"������", // description
	15, 3, 1, // damage resistance regeneration
	35, 35 // hp xp
); //


Enemy Box = Enemy(
	"�������", // name
	" _\n|_|\n", // description
	0, 5, 0, // damage resistance regeneration
	200, 15 // hp xp
); //


Enemy ForestMonster = Enemy(
	"������ ��������", // name
	"�������� ��������� ������� ������", // description
	20, 3, 3, // damage resistance regeneration
	40, 40 // hp xp
); //


Enemy MiracleLight = Enemy(
	"�������� ������", // name
	"*", // description
	10, 0, 5, // damage resistance regeneration
	60, 30 // hp xp
); //


Enemy Spider = Enemy(
	"����", // name
	"������� � ������", // description
	10, 2, 2, // damage resistance regeneration
	40, 35 // hp xp
); //


Enemy Troll = Enemy(
	"������", // name
	"�������, �����, �������...", // description
	24, 0, 0, // damage resistance regeneration
	40, 30 // hp xp
); //


Enemy Ghost = Enemy(
	"�������", // name
	"�� ��� ��������� � ����� ������ �����", // description
	13, 1, 3, // damage resistance regeneration
	25, 25 // hp xp
); //


Enemy Kozel = Enemy(
	"�����", // name
	"��������, ������ �� ����", // description
	17, 0, 1, // damage resistance regeneration
	30, 25 // hp xp
); //


Enemy Chest = Enemy(
	"������", // name
	"������ ��� ������� ��� ��� ��������...", // description
	15, 2, 2, // damage resistance regeneration
	40, 35 // hp xp
);


// Enemies Lists


Enemy enemylist[enemy_count] = {
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


Enemy bosslist[boss_count] = {
	KingLichBoss,
	MotherDemon,
	Demon12,
	Revenant,
	MM,
	AdamSmasher
};

