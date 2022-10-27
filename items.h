#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Object {
public:
    int id;
    string name;
};


class Item : public Object {
public:
    string rare, description;
    int cost;
protected:
    int weight;
};


class Weapon : public Item {
public:
    Weapon() {
        id = 0;
        cost = 0;
        weight = 0;
        damage = 0;
        rare = "default";
        name = "";
        description = "";
    }
    Weapon(int id_, int cost_, int weight_,
        float damage_, 
        string rare_, string name_,
        string description_) {
        id = id_;
        cost = cost_;
        weight = weight_;
        damage = damage_;
        rare = rare_;
        name = name_;
        description = description_;
    }

    float damage;

    void add_damage(float add) {
        damage += add;
    }
};


class Armor : public Item {
public:
    Armor() {
        id = 0;
        cost = 0;
        weight = 0;
        protection = 0;
        regeneration = 0;
        damage_boost = 0;
        rare = "default";
        name = "";
        description = "";
    }
    Armor(int id_, int cost_, int weight_,
        float protection_, float regeneration_, float damage_boost_,
        string rare_, string name_,
        string description_) {
        id = id_;
        cost = cost_;
        weight = weight_;
        protection = protection_;
        regeneration = regeneration_;
        damage_boost = damage_boost_;
        rare = rare_;
        name = name_;
        description = description_;
    }

    float protection,
        regeneration,
        damage_boost;

    void add_protection(float add) {
        protection += add;
    }

    void add_regeneration(float add) {
        regeneration += add;
    }

    void add_damage_boost(float add) {
        damage_boost += add;
    }
};


class Helmet : public Armor {
    using Armor::Armor;
};


class Chestplate : public Armor {
    using Armor::Armor;
};


class Leggings : public Armor {
    using Armor::Armor;
};


class Boots : public Armor {
    using Armor::Armor;
};


class Backpack : Item {
public:
    Backpack() {
        weight = 0;
    };
    int value = 10;
    int max_weight = 50;

private:
    vector <Weapon> weapones;
    vector <Item> items;
    vector <Armor> armors;
};


#endif
