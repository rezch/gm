#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include "CREATURES.H"
using namespace std;


void inventory_menu(Player player) {
	
}


void skill_points_menu(int(&skills)[5], int points) {
	while (points > 0) {
		cout << "Вам доступно " << points << " очков умений\nЧтобы распределить их нажмите:\n" <<
			"сила - 1\nловкость - 2\nинтелект - 3\nвзлом - 4\nвосстановление - 5\n";
		int choose = _getch();
		switch (choose) {
		case 49:
			skills[0]++;
			points--;
			break;
		case 50:
			skills[0]++;
			points--;
			break;
		case 51:
			skills[0]++;
			points--;
			break;
		case 52:
			skills[0]++;
			points--;
			break;
		case 53:
			skills[0]++;
			points--;
			break;
		}
		system("cls");
	}
}


void default_bar(Player& player) {
	cout << "hp: " << player.get_hp() << endl;
}


#endif
