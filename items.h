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
    string rare;
protected:
    int cost,
        weight;
};


class Weapon : public Item {
public:
    Weapon() {};
    Weapon(int id_, int cost_, int weight_,
        float damage_, string rare_, string name_,
        string description_) {
        id = id_;
        cost = cost_;
        weight = weight_;
        damage = damage_;
        rare = rare_;
        name = name_;
        description = description_;
    };

    float damage;
    int cost;
    string description;
};


class Armor : public Item {
public:
    int cost;
    float protection,
        regeneration,
        damage_boost;

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

