#include <iostream>
#include <string>


#include "Game.h"


int main() {

    std::string name;
    Item hand("Hand", 0, 0, Weapon), skin("Skin", 0, 0, Armour);
    Player player(name, hand, skin);

    Game testGame(player);
    testGame.play();

    return 0;
}