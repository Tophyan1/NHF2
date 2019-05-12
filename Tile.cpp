//
// Created by Gyuri on 2019. 04. 20..
//

#include "Tile.h"


void Tile::listItems() const {
    if (this->inventory.empty()) {
        std::cout << "There is no shop here!" << std::endl;
        return;
    }
    for (const auto &item : inventory) {
        std::cout << item.getName() << ' ';
    }
    std::cout << std::endl;
}



void Tile::sell(Player& player){
    if (this->inventory.empty()) {
        std::cout << "There is no item to buy!" << std::endl;
        return;
    }
    if (player.getGold() < inventory[0].getPrice()) {
        std::cout << "You don't have enough money." << std::endl;
        return;
    }
    player.getInventory().push_back(this->inventory[0]);
    player.getGold() -= this->inventory[0].getPrice();
    this->inventory.pop_back();
}

void Tile::buy(Player& player, std::string& itemName) {
    if (this->inventory.empty()) {
        std::cout << "There is no shop to sell to." << std::endl;
        return;
    }
    if (player.getInventory().empty()) {
        std::cout << "You don't have anything to sell. Face it, You are poor!" << std::endl;
        return;
    }
    for (auto &item : player.getInventory()) {
        if (item.getName() == itemName){
            player.getGold() += item.getPrice();
            player.getInventory().erase((std::vector<Item>::iterator)&item);
            return;
        }
    }
    std::cout << "You can only sell items in Your inventory!" << std::endl;
}