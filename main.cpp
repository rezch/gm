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
    Player player = Player(100, 5);
    upgrade_skills(player);
    return player;
}


void game_start() {
    Player player = make_new_player();
    save(player);
    bool game_procces = true;

    while (game_procces) {
        int input = _getch();

        switch (input) {
        case 105: // I
            inventory_menu(player);
            break;
        case 108: // L
            upgrade_skills(player);
            break;
        case 109: // M
            //map_menu(player);
            break;
        case 115: // S
            save(player);
            break;
        case 113: // Q
            save(player);
            game_procces = false;
            break;
        }
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    game_start();

    return 0;
}
