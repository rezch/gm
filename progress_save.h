#ifndef PROGRESS_SAVE
#define PROGRESS_SAVE
#include <iostream>
#include <fstream>
//#include <json/writer.h>
#include <string>
#include "CREATURES.H"
using namespace std;

bool save(Player& player) {
	if (player.in_battle) {
		return 0;
	}

	

	/*ifstream fin("log.xml", ios::in);
	ostream fout("log.xml", ios::out | std::ofstream::trunc);
	
	fin.close();
	fout.close();*/
}

#endif

