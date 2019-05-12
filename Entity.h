//
// Created by Gyuri on 2019. 04. 11..
//

#ifndef NHF2_ENTITY_H
#define NHF2_ENTITY_H

#include <string>
#include <random>
#include <chrono>

#include "Item.h"

class Entity {
protected:
    std::string name;
    int HP;
    unsigned int maxHP;
    unsigned int strength;
    unsigned int defense;
    int luck;
    Item armour;
    Item weapon;


public:
    Entity(std::string &name, int hp, unsigned int maxHp, unsigned int strength, unsigned int defense, int luck,
           Item &armour, Item &weapon) : name(std::move(name)), HP(hp), maxHP(maxHp), strength(strength),
                                                     defense(defense), luck(luck), armour(armour),
                                                     weapon(weapon){}



    std::string & getName() {
        return this->name;
    }

    int & getHp() {
        return this->HP;
    }

    unsigned int getMaxHp() {
        return this->maxHP;
    }

    unsigned int getStrength() const {
        return this->strength;
    }

    unsigned int getDefense() const {
        return this->defense;
    }

    const int getLuck() const {
        return this->luck;
    }

    Item & getArmour() {
        return this->armour;
    }

    Item & getWeapon() {
        return this->weapon;
    }

    virtual ~Entity() = default;

};


#endif //NHF2_ENTITY_H
