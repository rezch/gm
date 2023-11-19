#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include "items_list.h"
using namespace std;

const int SKILLS_COUNT = 5;
const float upgrade_k = 2;
const short int helth_potion_cost = 45;
const short int trader_save_cost = 50;
const short int helth_potion_regeneration = 15;

const string skill_names[SKILLS_COUNT] = { "power", // сила
        "agility", // ловкость
        "full_hp", // здоровье
        "parrying", // парирование
        "healing" // восстановление
};


class Player {
public:
    Player() {
        full_hp = 100;
        hp = 100;
        skill_points = 5;
        money = 500;
        trader_save = false;

        set_weapon(1);
        set_helmet(1);
        set_chestplate(1);
        set_leggings(1);
        set_boots(1);

        for (const auto& skill_name : skill_names) {
            skills[skill_name] = 0;
        }
    };
    Player(int full_hp_, int points) {
        *this = Player();

        full_hp = full_hp_;
        hp = full_hp_;
        skill_points = points;
        money = 500;
        trader_save = false;
    };
    Player(int hp_, int points, int(&skill_list)[5]) {
        hp = hp_;
        skill_points = points;

        for (int i = 0; i < SKILLS_COUNT; i++) {
            skills[skill_names[i]] = skill_list[i];
        }
    };

    // public varibales
    bool in_battle = false;
    bool trader_save{};
    int item_updrade_cost = 50;
    float weapon_upgrade_k = 1,
        helmet_upgrade_k = 1,
        chestplate_upgrade_k = 1,
        leggings_upgrade_k = 1,
        boots_upgrade_k = 1;

    // pve
    int attack() {
        // damage from 80 to 100 %
        return (weapon.damage * weapon_upgrade_k +
                + skills["agility"] * 0.25
                + skills["power"])
            * random(80, 100) / 100;
    }

    void add_hp(int hp_points) {
        hp += hp_points;
        if (hp > get_full_hp()) {
            hp = get_full_hp();
        }
    }

    [[nodiscard]] int get_hp() const {
        return hp;
    }

    void set_full_hp(int points) {
        full_hp = points;
    }

    int get_full_hp() {
        return full_hp + 10 * skills["full_hp"];
    }

    [[nodiscard]] int get_full_hp_save_value() const {
        return full_hp;
    }

    [[nodiscard]] bool is_dead() const {
        return hp <= 0;
    }

    int parrying(int damage) {
        after_step();
        damage /= (skills["parrying"] + 10) + damage * random(25, 50) / 100;
        if (damage > 0) {
            hp -= damage;
        }
        return (int)(helmet_upgrade_k +
                chestplate_upgrade_k +
                leggings_upgrade_k +
                boots_upgrade_k)
            * random(80, 100) / 100;
    }

    void take_damage(int damage) {
        damage -= (int)((helmet_upgrade_k +
                   chestplate_upgrade_k +
                   leggings_upgrade_k +
                   boots_upgrade_k)
            * (float)skills["parrying"]
            * (float)random(80, 100) / 100
            * 0.6);

        if (damage > 0) {
            hp -= damage;
        }

        hp = max(0, hp);
    }

    // after step of fight abilities
    void after_step() {
        if (hp < 1) return;

        hp += (int)((float)skills["healing"] * 0.1 * get_full_hp());
        if (hp > get_full_hp()) {
            hp = get_full_hp();
        }
    };

    // xp
    [[nodiscard]] int get_xp() const {
        return xp;
    }

    void add_xp(int xp_points) {
        if (xp_points > 0) {
            xp += xp_points;
        }
    }

    [[nodiscard]] int get_level() const {
        return xp / 10;
    }

    //money
    [[nodiscard]] int get_money() const {
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

    void add_skillpoints(int points) {
        skill_points += points;
    }

    [[nodiscard]] int get_skillpoints() const {
        return skill_points;
    }

    void set_skillpoints(int points) {
        if (points >= 0) {
            skill_points = points;
        }
    }

    map <string, int> get_skills() {
        return skills;
    }

    // Items
    // Weapon
    void weapon_upgrade() {
        weapon_upgrade_k = 1 + weapon_upgrade_k * upgrade_k;
    }

    Weapon& get_weapon() {
        return weapon;
    }

    void set_weapon(int weapon_id) {
        weapon = weapons_list[weapon_id];
    }

    // Helmet
    void helmet_upgrade() {
        helmet_upgrade_k = 1 + helmet_upgrade_k * upgrade_k;
    }

    Helmet& get_helmet() {
        return helmet;
    }

    void set_helmet(int helmet_id) {
        helmet = helmets_list[helmet_id];
    }
    
    // Chestplate
    void chestplate_upgrade() {
        chestplate_upgrade_k = 1 + chestplate_upgrade_k * upgrade_k;
    }

    Chestplate& get_chestplate() {
        return chestplate;
    }

    void set_chestplate(int chestplate_id) {
        chestplate = chestplate_list[chestplate_id];
    }

    // Leggings
    void leggings_upgrade() {
        leggings_upgrade_k = 1 + leggings_upgrade_k * upgrade_k;
    }

    Leggings& get_leggings() {
        return leggings;
    }

    void set_leggings(int leggings_id) {
        leggings = leggings_list[leggings_id];
    }

    // Boots
    void boots_upgrade() {
        boots_upgrade_k = 1 + boots_upgrade_k * upgrade_k;
    }

    Boots& get_boots() {
        return boots;
    }

    void set_boots(int boots_id) {
        boots = boots_list[boots_id];
    }

    // set item to appropriate player item
    template <typename Type>
    void set_item(Type& item) {
        if (is_same<Type, Weapon>::value) {
            weapon = (Weapon&)item;
        }
        if (is_same<Type, Helmet>::value) {
            helmet = (Helmet&)item;
        }
        if (is_same<Type, Chestplate>::value) {
            chestplate = (Chestplate&)item;
        }
        if (is_same<Type, Leggings>::value) {
            leggings = (Leggings&)item;
        }
        if (is_same<Type, Boots>::value) {
            boots = (Boots&)item;
        }
    }

    // get item to appropriate player item
    template <typename Type>
    Type& get_item(Type& type) {
        if (is_same<Type, Weapon>::value) {
            return (Type&)get_weapon();
        }
        if (is_same<Type, Helmet>::value) {
            return (Type&)get_helmet();
        }
        if (is_same<Type, Chestplate>::value) {
            return (Type&)get_chestplate();
        }
        if (is_same<Type, Leggings>::value) {
            return (Type&)get_leggings();
        }
        if (is_same<Type, Boots>::value) {
            return (Type&)get_boots();
        }
    }

private:
    // specifications
    int full_hp{},
        hp{},
        skill_points{},
        xp{},
        money{};

    // Items
    Weapon weapon;
    Helmet helmet;
    Chestplate chestplate;
    Leggings leggings;
    Boots boots;
    
    // Skills
    map <string, int> skills;
};


class Enemy {
public:
    Enemy(string name_, string description_,
        int damage_, float resistance_, int regeneration_,
        int hp_, int xp_) :
        name(std::move(name_)),
        description(std::move(description_)),
        full_hp(hp_),
        hp(full_hp),
        damage(damage_),
        regeneration(regeneration_),
        xp(xp_),
        resistance(resistance_)
    {};

    string name;
    string description;
    int full_hp;

    [[nodiscard]] int attack() const {
        // from 80 to 100 % of damage
        return damage * random(80, 100) / 100;
    }

    [[nodiscard]] int get_hp() const {
        return hp;
    }

    [[nodiscard]] int get_xp() const {
        return xp;
    }

    [[nodiscard]] bool is_dead() const {
        return hp <= 0;
    }

    void take_damage(int taken_damage) {
        // from 80 to 100 % of resistance
        taken_damage -= (int)(resistance * (float)random(30, 100) / 100);
        if (taken_damage > 0) {
            hp -= taken_damage;
        }
        hp = max(0, hp);
    }

    // after step of fight abilities
    void after_step() {
        if (hp < 1) return;

        hp += regeneration;
        if (hp > full_hp) {
            hp = full_hp;
        }
    }

private:
    int hp,
        damage,
        regeneration,
        xp;
    float resistance;
};

#endif
