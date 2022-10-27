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
    if (log_is_empty("log.json")) {
        Player player = Player(100, 5);
        upgrade_skills(player);
        return player;
    }
    Player player = load();
    return player;
}


void game_start() {
    Player player = make_new_player();
    save(player);
    bool game_procces = true;

    while (game_procces) {
        cls();
        txt_message("txt/help.txt");
        int input = _getch();

        switch (input) {
        case 105: // I
            inventory_menu(player);
            break;
        case 108: // L
            upgrade_skills(player);
            break;
        case 109: // M
            map_menu(player);
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
    //Player player = load();
    //dropped_item_choose(player, 0, 2);
    /*int input;
    while (true) {
        pair <int, int> p = get_random_item_id();
        switch (p.first) {
        case 0:
            cout << weapons_list[p.second].name << endl;
            break;
        case 1:
            cout << helmets_list[p.second].name << endl;
            break;
        case 2:
            cout << chestplate_list[p.second].name << endl;
            break;
        case 3:
            cout << leggings_list[p.second].name << endl;
            break;
        case 4:
            cout << boots_list[p.second].name << endl;
            break;
        }
        input = _getch();
    }
    */
    return 0;
}
