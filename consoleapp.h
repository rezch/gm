#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;


const short int cyan = 3;
const short int green = 2;
const short int purple = 5;
const short int yellow = 6;
const short int red = 4;
const short int red_font = 64;
const short int yellow_font = 96;

const short int hp_color = red;
const short int xp_color = green;
const short int weapon_color = cyan;
const short int armor_color = cyan;
const short int cost_color = yellow;
const short int weapon_properties = red;
const short int armor_properties = purple;


void cls() {
	system("cls");
}


void ccout(string text, int color, bool endline) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	if (endline) {
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
}


void dout(int a, int b) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (a < b) {
		SetConsoleTextAttribute(hConsole, 4);
		cout << '(' << a - b << ')';
	}
	else {
		SetConsoleTextAttribute(hConsole, 2);
		cout << "(+" << a - b << ')';
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n";
}


void txt_message(string filename) {
	ifstream file(filename, ios::in);
	while (true) {
		string line;
		getline(file, line);
		if (file.eof()) {
			break;
		}
		cout << line << endl;
	}
	file.close();
}


void txt_message_skills(string filename, int(&skills)[SKILLS_COUNT]) {
	ifstream file(filename, ios::in);
	int i = 0;
	while (true) {
		string line;
		getline(file, line);
		if (file.eof()) {
			break;
		}
		cout << line << skills[i] << endl;
		i++;
	}
	file.close();
}


#endif

