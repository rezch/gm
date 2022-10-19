#include <iostream>
#include <map>
#include <conio.h>
#include <locale.h>
#include "creatures.h"
#include "items.h"
#include "menuoptions.h"
#include "progress_save.h"
using namespace std;


Player make_new_player() {
    int skills[5] = { 0, 0, 0, 0, 0 };
    int points = 5;
    //skill_points_menu(skills, points);
    Player player = Player(100, points, skills);
    
    return player;
}


int main() {
    setlocale(LC_ALL, "Russian");
    Player player = make_new_player();
    save(player);
    return 0;
}
