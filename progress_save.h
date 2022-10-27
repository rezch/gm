#ifndef PROGRESS_SAVE_H
#define PROGRESS_SAVE_H
#include <iostream>
#include <json\json.h>
#include <fstream>
#include <string>
#include "CREATURES.H"
using namespace std;

const string armor_names[4] = {
	"helmet_id",
	"chest_id",
	"legs_id",
	"boots_id"
};


bool log_is_empty(string file_name) {
	ifstream file(file_name, ios::in);
	return file.peek() == ifstream::traits_type::eof();
}


Player load() {
	ifstream log_file("log.json", std::ifstream::binary);
	Json::Value root;
	log_file >> root;

	int skill_list[SKILLS_COUNT];
	for (int i = 0; i < SKILLS_COUNT; i++) {
		skill_list[i] = root["Player"]["skills"][i].asInt();
	}

	// Player vars
	Player player = Player(
		root["Player"]["hp"].asInt(),
		root["Player"]["skill_points"].asInt(),
		skill_list
		);
	player.set_full_hp(root["Player"]["full_hp"].asInt());
	player.add_xp(root["Player"]["xp"].asInt());
	player.add_money(root["Player"]["money"].asInt());

	// trader
	player.item_updrade_cost = root["Trader"]["cost"].asFloat();
	player.trader_save = root["Trader"]["item_save"].asBool();

	// items
	player.set_weapon(root["Player"]["Items"]["weapon_id"].asInt());
	player.set_helmet(root["Player"]["Items"]["helmet_id"].asInt());
	player.set_chestplate(root["Player"]["Items"]["chest_id"].asInt());
	player.set_leggings(root["Player"]["Items"]["legs_id"].asInt());
	player.set_boots(root["Player"]["Items"]["boots_id"].asInt());

	// upgrades
	player.weapon_upg = root["Player"]["Items"]["weapon_upgrade"].asFloat();

	player.helmet_upg = root["Player"]["Items"]["helmet_upgrade"].asFloat();
	player.chestplate_upg = root["Player"]["Items"]["chestplate_upgrade"].asFloat();
	player.leggings_upg = root["Player"]["Items"]["leggings_upgrade"].asFloat();
	player.boots_upg = root["Player"]["Items"]["boots_upgrade"].asFloat();
	
	return player;
}


bool save(Player& player) {
	if (player.in_battle) {
		return 0;
	}

	// making json root
	Json::Value root;
	
	// trader
	root["Trader"]["cost"] = player.item_updrade_cost;
	root["Trader"]["item_save"] = player.trader_save;
	
	// Player vars
	root["Player"]["full_hp"] = player.get_full_hp_save_value();
	root["Player"]["hp"] = player.get_hp();
	root["Player"]["xp"] = player.get_xp();
	root["Player"]["money"] = player.get_money();
	
	Json::Value skills_json(Json::arrayValue);
	map <string, int> skills = player.get_skills();
	for (auto& name : skill_names) {
		skills_json.append(skills[name]);
	}

	root["Player"]["skills"] = skills_json;
	root["Player"]["skill_points"] = player.get_skillpoints();

	root["Player"]["Items"]["weapon_id"] = player.get_weapon().id;
	root["Player"]["Items"]["helmet_id"] = player.get_helmet().id;
	root["Player"]["Items"]["chest_id"] = player.get_chestplate().id;
	root["Player"]["Items"]["legs_id"] = player.get_leggings().id;
	root["Player"]["Items"]["boots_id"] = player.get_boots().id;
	
	// upgrades
	root["Player"]["Items"]["weapon_upgrade"] = player.weapon_upg;

	root["Player"]["Items"]["helmet_upgrade"] = player.helmet_upg;
	root["Player"]["Items"]["chestplate_upgrade"] = player.chestplate_upg;
	root["Player"]["Items"]["leggings_upgrade"] = player.leggings_upg;
	root["Player"]["Items"]["boots_upgrade"] = player.boots_upg;


	// writing to file
	ifstream fin("log.json", ios::in);
	ofstream fout("log.json", ios::out | std::ofstream::trunc);

	fout << root << endl;

	fin.close();
	fout.close();
	return 1;
}

#endif
