#ifndef NHF2_TILE_H
#define NHF2_TILE_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Monster.h"



/**
 *
 * Class that acts as the position the player is in
 *
 * */
class Tile {
private:

    /**
     * String that stores the story of the location
     * */
    std::string story;
    /**
     * A pointer to a potential monster
     * */
    std::shared_ptr<Monster> monster;
    /**
     * In case of a shop, it has an inventory
     * */
    std::vector<Item> inventory;


public:

    ///Constructor for simple tiles and ones with a monster
    Tile(std::string story, std::shared_ptr<Monster> monster = nullptr) : story(std::move(story)), monster(std::move(monster)) {}
    ///Constructor for a shop tile
    Tile (std::string story, std::vector<Item> inventory) : story(std::move(story)), monster(nullptr), inventory(std::move(inventory)) {}

    ///Getter for the story
    const std::string &getStory() const {
        return this->story;
    }

    ///Getter for the monster
    Monster &getMonster() {
        if (monster == nullptr)
            throw std::domain_error("There is no monster.");
        return *monster;
    }

    ///Getter for the monster's pointer
    std::shared_ptr<Monster> ptrToMonster() {
        return monster;
    }

    ///Assignment operator
    ///\param rhs the right-hand-side Tile
    Tile& operator=(const Tile& rhs) {
        this->story = rhs.story;
        if (rhs.monster) {
            auto tmp = std::make_shared<Monster>(*(rhs.monster));
            this->monster.swap(tmp);
        }
        else
            this->monster.reset();
        this->inventory = rhs.inventory;
        return *this;
    }

    ///Prints story to screen
    void tellStory() const {
        std::cout << this->story << std::endl;
    }

    ///Function that lists the items in inventory to standard output
    void listItems() const;


    /// Sells an item to a player
    /// \param player The player who interacts with the shop
    void sell(Player& player);

    /// Buys an item from a player
    /// \param player The player interacting with the shop
    /// \param itemName Name of the item to buy
    void buy(Player& player, std::string& itemName);

    ///Default Destructor
    ~Tile() = default;

};


#endif //NHF2_TILE_H
