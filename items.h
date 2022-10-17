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


class Backpack : public Item {
public:
    Backpack() {};
    Backpack(int vol, int max_wght) {
        volume = vol;
        max_weight = max_wght;
    }
private:
    int volume,
        max_weight;
};


class Armor : public Item {
private:
    int cost;
    float protection,
        regeneration,
        damage_boost;

};

#endif

