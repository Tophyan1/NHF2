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
        std::cout << item.getName() << '\t';
    }
    std::cout << std::endl;
}



void Tile::sell(Player& player, std::string& itemName){
    if (this->inventory.empty()) {
        std::cout << "There is no item to buy!" << std::endl;
        return;
    }
    for (auto &i : this->inventory) {
        if (i.getName() == itemName) {
            if (i.getPrice() > player.getGold()) {
                std::cout << "You don't have enough money!" << std::endl;
                return;
            }
            player.getInventory().push_back(i);
            player.getGold() -= i.getPrice();
            this->inventory.erase((std::vector<Item>::iterator)&i);
            return;
        }
    }
}

void Tile::buy(Player& player, std::string& itemName) {
    if (player.getInventory().empty()) {
        std::cout << "You don't have anything to sell. Face it, You are poor!" << std::endl;
    }
    for (auto &item : inventory) {
        if (item.getName() == itemName){
            player.getGold() += item.getPrice();
            player.getInventory().erase((std::vector<Item>::iterator)&item);
            return;
        }
    }
    std::cout << "You can only sell items in Your inventory!" << std::endl;
}