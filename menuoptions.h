#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "items.h"
#include "CREATURES.H"
using namespace std;


void cls() {
	system("cls");
}

void inventory_menu(Player& player) {

}


int skill_points_menu(int(&skills)[5], int points) {
	bool menu_is_on = true;
	while (points > 0 && menu_is_on) {
		cout << "Вам доступно " << points << " очков умений\nЧтобы распределить их нажмите:\n" <<
			"сила - 1\nловкость - 2\nинтелект - 3\nвзлом - 4\nвосстановление - 5\nвыйти - q\n";
		int choose = _getch();
		switch (choose) {
		case 49:
			skills[0]++;
			points--;
			break;
		case 50:
			skills[1]++;
			points--;
			break;
		case 51:
			skills[2]++;
			points--;
			break;
		case 52:
			skills[3]++;
			points--;
			break;
		case 53:
			skills[4]++;
			points--;
			break;
		case 113:
			menu_is_on = false;
			break;
		}
		cls();
	}
	return points;
}


void upgrade_skills(Player& player) {
	int skills_list[5];
	player.skills_to_list(skills_list);
	int free_points = skill_points_menu(skills_list, player.get_skillpoints());
	player.set_skillpoints(free_points);
	player.list_to_skills(skills_list);
}

#endif
