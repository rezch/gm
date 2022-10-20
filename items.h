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
protected:
    int cost,
        weight;
};


class Weapon : public Item {
private:
    float damage;
    int cost;
    string description;
};


class Armor : public Item {
private:
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
    vector <Weapon> weapones();
    vector <Item> items();
    vector <Armor> armors();
};


#endif

