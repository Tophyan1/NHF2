#ifndef NHF2_GAME_H
#define NHF2_GAME_H

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <chrono>
#include <memory>
#include <map>
#include <regex>
#include <fstream>

#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "Tile.h"
#include "Item.h"


/***
 *
 * */
class Game {
private:
    Player player;
    Tile tile;
    //std::shared_ptr<Tile> tile;
    std::mt19937 generator;

public:

    ///Constructor
    Game(Player &player) : player(player), tile(Tile("Init")),
                            generator(std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count())) {

    }



    void forward();



    void getHelp() const;

    void battle();

    void play();

    ~Game() = default;

};

#endif //NHF2_GAME_H
