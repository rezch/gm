#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

class Object {
public:
    int id{};
    string name;
};


class Item : public Object {
public:
    int cost{};
    string name, rare, description;
    int id{};
};


class PlayerItem : public Item {
protected:
    float damage{},
        protection{},
        regeneration{},
        damage_boost{};
};


class Weapon : public PlayerItem {
public:
    Weapon() {
        id = 0;
        cost = 0;
        damage = 0;
        rare = "default";
        name = "";
        description = "";
    }
    Weapon(int id_, int cost_, float damage_, 
        string rare_, string name_, string description_) {
        id = id_;
        cost = cost_;
        damage = damage_;
        rare = std::move(rare_);
        name = std::move(name_);
        description = std::move(description_);
    }

    float damage;

    void add_damage(float add) {
        damage += add;
    }
};


class Armor : public PlayerItem {
public:
    Armor() {
        id = 0;
        cost = 0;
        protection = 0;
        regeneration = 0;
        damage_boost = 0;
        rare = "default";
        name = "";
        description = "";
    }
    Armor(int id_, int cost_, float protection_, float regeneration_, float damage_boost_,
        string rare_, string name_, string description_) {
        id = id_;
        cost = cost_;
        protection = protection_;
        regeneration = regeneration_;
        damage_boost = damage_boost_;
        rare = std::move(rare_);
        name = std::move(name_);
        description = std::move(description_);
    }

    float protection,
        regeneration,
        damage_boost;
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

