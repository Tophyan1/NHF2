
#include "Player.h"



void Player::drink() {
    for (auto &item : inventory) {
        if (item.getName() == "Potion"){
            this->HP += item.getEffect();
            if ((unsigned int)this->HP > this->maxHP){
                this->HP = this->maxHP;
            }
            this->inventory.erase((std::vector<Item>::iterator)(&item));
            std::cout << "You have drank a potion. Your health is " << this->HP << std::endl;
            return;
        }
    }
    std::cout << "There were no potions for You to drink. You should have been more sparing..." << std::endl;
}

void Player::askName() {
    std::cout << "Please enter Your name!" << std::endl;
    std::cout << ">";
    std::getline(std::cin, this->name);
}


void Player::stats() const {
    std::cout << "Your stats:\n"
                    "\tname: " << this->name << "\n"
                    "\thp: " << this->HP << " out of " << this->maxHP << "\n"
                    "\tstrength: " << this->strength << "\n"
                    "\tdefense: " << this->defense << "\n"
                    "\tluck: " << this->luck << "\n"
                    "\tarmour: " << this->armour.getName() << "(" << this->armour.getEffect() << " def)\n"
                    "\tweapon: "  << this->weapon.getName() << "(" << this->weapon.getEffect() << " str)" << std::endl;
}
