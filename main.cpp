#include <iostream>
#include "creatures.h"
#include "items.h"
using namespace std;


int main() {
    Player player = Player(188);
    cout << player.get_hp();

    Backpack def_pack = Backpack(5, 20);
    return 0;
}
