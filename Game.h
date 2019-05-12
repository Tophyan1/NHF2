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
 * Class to manage the whole game
 * */
class Game {
private:
    ///Player whho plays the game
    Player player;
    ///Current Tile
    Tile tile;
    ///Mersenne-twister genrator
    std::mt19937 generator;
public:
    ///Constructor
    Game(Player &player) : player(player), tile(Tile("Init")),
                            generator(std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count())) {}
    ///Changes Tile
    void forward();
    ///Lists possible commands to standard output
    void getHelp() const;
    ///Runs a battle between player and current monster
    void battle();
    ///Controls Gameplay
    void play();
    ///Default Destructor
    ~Game() = default;
};
#endif //NHF2_GAME_H
