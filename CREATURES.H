#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <iostream>
#include "items.h"

class Player {
public:
    Player() {};
    Player(int full_hp) {
        hp = full_hp;
    };

    int get_hp() {
        return hp;
    };
    void take_damage(int damage) {
        hp -= damage;
    };
private:
    int hp;
    Weapon weapon;

    Armor helmet,
        chestplate,
        leggings,
        boots;

    Backpack backpack;
};


class Enemy {
public:
    std::string name;
    std::string description;
private:
    int hp,
        damage,
        regeneration;
    float resistance;
};

#endif
