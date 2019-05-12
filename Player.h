#ifndef NHF2_PLAYER_H
#define NHF2_PLAYER_H

#include <set>
#include <string>
#include <random>
#include <chrono>
#include <iostream>

#include "Entity.h"
#include "Item.h"

/**
 * Player claass
 * */
class Player : public Entity{
private:
    /// Inventory of player
    std::vector<Item> inventory;
    /// amount of gold
    unsigned int gold;
public:
    ///Constructor
    Player(std::string& name, Item& weapon, Item& armour) : Entity(name, 100, 100, 20, 15, 10, armour, weapon), gold(200) {
        for (int i = 0; i < 3; ++i){
            this->inventory.emplace_back(Item("Potion", 0, 30, Potion));
        }
    }
    ///Getter/setter for inventory
    std::vector<Item> &getInventory() {
        return this->inventory;
    }
    ///Function to set the name of Player
    void askName();
    ///Getter/setter for gold
    unsigned int &getGold() {
        return this->gold;
    }
    ///Lists content of inventory to standard output
    void listInventory() const {
        for (const auto &item : inventory) {
            std::cout << item.getName() << ' ';
        }
        std::cout << std::endl;
    }
    ///Lists stats to standatd output
    void stats() const;
    ///Uses a potion
    void drink();
    ///Default destructor
    ~Player() override = default;
};
#endif //NHF2_PLAYER_H
