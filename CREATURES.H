#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "items.h"
using namespace std;

const int SKILLS_COUNT = 5;

class Player {
public:
    Player() {};
    Player(int full_hp, int points, int* skills_list) {
        hp = full_hp;
        skill_points = points;
        backpack = Backpack();

        int i = 0;
        for (auto& skill : skill_names) {
            skills[skill] = skills_list[i];
            i++;
        }
    };

    // public varibales
    bool in_battle = false;
    Backpack backpack;

    // hp constructor
    int get_hp() {
        return hp;
    };
    void take_damage(int damage) {
        hp -= damage;
    };

    // skills constructor
    void upgrade_skill_power(int skill_id) {
        skill_points--;
    }

private:
    // specifications
    int hp;
    int skill_points;

    // Items
    Weapon weapon;
    Armor helmet,
        chestplate,
        leggings,
        boots;
    
    // Skills
    string skill_names[SKILLS_COUNT] = { "power", // сила
        "agility", // ловкость
        "intelligence", // интелект
        "hack", // взлом
        "healing" // восстановление
    };
    map <string, int> skills;
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
