#ifndef NHF2_PLAYER_H
#define NHF2_PLAYER_H

#include <set>
#include <string>
#include <random>
#include <chrono>
#include <iostream>

#include "Entity.h"
#include "Item.h"

class Player : public Entity{
private:
    std::vector<Item> inventory;
    unsigned int gold;

public:
    Player(std::string& name, Item& weapon, Item& armour) : Entity(name, 100, 100, 20, 15, 10, armour, weapon), gold(200) {
        for (int i = 0; i < 3; ++i){
            this->inventory.emplace_back(Item("Potion", 0, 30, Potion));
        }

    }

    std::vector<Item> &getInventory() {
        return this->inventory;
    }

    void askName();



    unsigned int &getGold() {
        return this->gold;
    }

    void listInventory() const {
        for (const auto &item : inventory) {
            std::cout << item.getName() << '\t';
        }
        std::cout << std::endl;
    }

    void stats() const;

    void drink();



};


#endif //NHF2_PLAYER_H
