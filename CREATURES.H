#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "items.h"
using namespace std;

const int SKILLS_COUNT = 5;

const string skill_names[SKILLS_COUNT] = { "power", // сила
        "agility", // ловкость
        "intelligence", // интелект
        "hack", // взлом
        "healing" // восстановление
};


class Player {
public:
    Player() {};
    Player(int full_hp, int points) {
        hp = full_hp;
        skill_points = points;
        backpack = Backpack();

        for (int i = 0; i < SKILLS_COUNT; i++) {
            skills[skill_names[i]] = 0;
        }
    };

    // public varibales
    bool in_battle = false;
    Backpack backpack;

    // hp
    int get_hp() {
        return hp;
    };

    void take_damage(int damage) {
        hp -= damage;
    };

    // skills constructor
    void skills_to_list(int (&skills_list)[SKILLS_COUNT]) {
        int i = 0;
        for (auto& skill_name : skill_names) {
            skills_list[i] = skills[skill_name];
            i++;
        }
    }

    void list_to_skills(int(&skills_list)[SKILLS_COUNT]) {
        for (int i = 0; i < SKILLS_COUNT; i++) {
            skills[skill_names[i]] = skills_list[i];
        }
    }

    int get_skillpoints() {
        return skill_points;
    }

    void set_skillpoints(int points) {
        if (points > 0) {
            skill_points = points;
        }
    }

    map <string, int> get_skills() {
        return skills;
    }

    // Items 
    Weapon get_weapon() {
        return weapon;
    }

    vector <Armor> get_armor() {
        return vector <Armor> {helmet, 
            chestplate, 
            leggings, 
            boots
        };
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
