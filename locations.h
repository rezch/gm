#pragma once
#include <string>
#include <vector>
#include "items_list.h"
#include "enemies.h"

using namespace std;

namespace locations_variables {
    map<int, vector<Enemy>> enemies_list = {
            {0, vector<Enemy>{}},
            {1, vector<Enemy>{
                    Slime,
                    Skeleton,
                    Box,
                    ForestMonster,
                    MiracleLight,
                    Spider,
                    Troll,
                    Ghost,
                    Kozel,
                    Chest
            }},
    };

    map<int, vector<Enemy>> bosses_list = {
            {0, vector<Enemy>{}},
            {1, vector<Enemy>{
                    Revenant
            }}
    };
}


class Location {

public:

    Location() = default;
    Location(string name, string description, int id) : name_(std::move(name)), description_(std::move(description)), id_(id) {}

    [[nodiscard]] string& name() const {
        return (string&)this->name_;
    }

    [[nodiscard]] string& description() const {
        return (string&)this->description_;
    }

	[[nodiscard]] Enemy get_enemy() const {
        return locations_variables::enemies_list[this->id_][
                    random(0, (int)locations_variables::enemies_list[this->id_].size())
                ];
    }

	[[nodiscard]] Enemy get_boss() const {
        return locations_variables::bosses_list[this->id_][
                random(0, (int)locations_variables::bosses_list[this->id_].size())
        ];
    }

protected:

    string name_{};
    string description_{};
    int id_{};

};


namespace Locations {
    Location Forest = Location(
            "Лес", // name
            "Темный таинственный лес", // description
            1 // id
    );
}