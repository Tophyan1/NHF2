#ifndef NHF2_TILE_H
#define NHF2_TILE_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Monster.h"

class Tile {
private:
    std::string story;
    std::shared_ptr<Monster> monster;
    std::vector<Item> inventory;


public:


    Tile(std::string story, std::shared_ptr<Monster> monster = nullptr) : story(std::move(story)), monster(std::move(monster)) {}

    Tile (std::string story, std::vector<Item> inventory) : story(std::move(story)), monster(nullptr), inventory(std::move(inventory)) {}

    const std::string &getStory() const {
        return this->story;
    }

    Monster &getMonster() {
        if (monster == nullptr)
            throw std::domain_error("There is no monster.");
        return *monster;
    }

    std::shared_ptr<Monster> ptrToMonster() {
        return monster;
    }


    void tellStory() const {
        std::cout << this->story << std::endl;
    }

    void listItems() const;


    void sell(Player& player, std::string& itemName);

    void buy(Player& player, std::string& itemName);

    ~Tile() = default;

};


#endif //NHF2_TILE_H
