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

        for (int i = 0; i < SKILLS_COUNT; i++) {
            skills[skill_names[i]] = 0;
        }
    };
    Player(int full_hp, int points, int (&skill_list)[5]) {
        hp = full_hp;
        skill_points = points;

        for (int i = 0; i < SKILLS_COUNT; i++) {
            skills[skill_names[i]] = skill_list[i];
        }
    };

    // public varibales
    bool in_battle = false;

    // xp
    int get_xp() {
        return xp;
    }

    void add_xp(int xp_points) {
        if (xp_points > 0) {
            xp += xp_points;
        }
    }

    //money
    int get_money() {
        return money;
    }
    
    void add_money(int sum) {
        if (sum > 0) {
            money += sum;
        }
    }

    void spend_money(int sum) {
        if (sum > 0) {
            money -= sum;
        }
    }

    // hp
    int get_hp() {
        return hp;
    };

    void take_damage(int damage) {
        if (damage > 0) {
            hp -= damage;
        }
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

    void set_weapon(int weapone_id) {

    }

    vector <Armor> get_armor() {
        return vector <Armor> {helmet, 
            chestplate, 
            leggings, 
            boots
        };
    }

    void set_helmet(int helmet_id) {

    }

    void set_chestplate(int chestplate_id) {

    }

    void set_leggings(int leggings_id) {

    }

    void set_boots(int weapon_id) {

    }

private:
    // specifications
    int hp,
        skill_points,
        xp,
        money;

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
    string name;
    string description;
private:
    int hp,
        damage,
        regeneration,
        xp;
    float resistance;
};

#endif
