#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <ctime>
#include <string>
#include "CREATURES.H"
using namespace std;


const short int enemy_count = 2;


Enemy Slime = Enemy(
	"Слизень", // name
	"Скользкий и противный", // description
	10, 1, 3, // damage resistance regeneration
	30, 30 // hp xp
);


Enemy Skeleton = Enemy(
	"Скелет", // name
	"Гремит", // description
	15, 3, 1, // damage resistance regeneration
	25, 35 // hp xp
);


Enemy enemylist[enemy_count] = {
	Slime,
	Skeleton
};


#endif
