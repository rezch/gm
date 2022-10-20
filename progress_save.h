#ifndef PROGRESS_SAVE_H
#define PROGRESS_SAVE_H
#include <iostream>
#include <json\json.h>
#include <fstream>
#include <string>
#include "CREATURES.H"
using namespace std;

const string armor_names[4] = {
	"head_id",
	"chest_id",
	"legs_id",
	"boots_id"
};


bool save(Player& player) {
	if (player.in_battle) {
		return 0;
	}

	// making json root
	Json::Value root;
	
	root["Player"]["hp"] = player.get_hp();
	
	Json::Value skills_json(Json::arrayValue);
	map <string, int> skills = player.get_skills();
	for (auto& name : player.skill_names) {
		skills_json.append(skills[name]);
	}

	root["Player"]["skills"] = skills_json;
	root["Player"]["skill_points"] = player.get_skillpoints();

	root["Player"]["Items"]["weapone_id"] = player.get_weapon().id;
	root["Player"]["Items"]["Armor"]["head_id"];
	int i = 0;
	for (auto& armor : player.get_armor()) {
		root["Player"]["Items"]["Armor"][armor_names[i]] = armor.id;
		i++;
	}

	// writing to file
	ifstream fin("log.json", ios::in);
	ofstream fout("log.json", ios::out | std::ofstream::trunc);

	fout << root << endl;

	fin.close();
	fout.close();
	return 1;
}

#endif

