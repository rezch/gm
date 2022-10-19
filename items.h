#ifndef ITEMS_H
#define ITEMS_H


class Object {
public:
    std::string name;
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
    std::string description;
};


class Backpack : Item {
public:
    Backpack() {
        weight = 0
    };
    int value = 10;
    int max_weight = 50;

private:
    vector <Weapon> weapones;
    vector <Item> items;
    vector <Armor> armors;
};


class Armor : public Item {
private:
    int cost;
    float protection,
        regeneration,
        damage_boost;

};



#endif

