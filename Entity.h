//
// Created by Gyuri on 2019. 04. 11..
//

#ifndef NHF2_ENTITY_H
#define NHF2_ENTITY_H

#include <string>
#include <random>
#include <chrono>

#include "Item.h"

/**
 * Generic Entity
 * */
class Entity {
protected:
    /// Name of entitiy
    std::string name;
    /// Current health
    int HP;
    /// Maximum health
    unsigned int maxHP;
    /// Attack power
    unsigned int strength;
    /// Protection
    unsigned int defense;
    /// Luck with attacks
    int luck;
    /// Currently worn armour
    Item armour;
    /// Currently used weapon
    Item weapon;
public:
    ///Constructor
    Entity(std::string &name, int hp, unsigned int maxHp, unsigned int strength, unsigned int defense, int luck,
           Item &armour, Item &weapon) : name(std::move(name)), HP(hp), maxHP(maxHp), strength(strength),
                                                     defense(defense), luck(luck), armour(armour),
                                                     weapon(weapon){}
    ///Getter for name
    std::string & getName() {
        return this->name;
    }
    ///Getter/setter for HP
    int & getHp() {
        return this->HP;
    }
    ///Getter for maxHP
    unsigned int getMaxHp() {
        return this->maxHP;
    }
    ///Getter for strength
    unsigned int getStrength() const {
        return this->strength;
    }
    ///Getter for defense
    unsigned int getDefense() const {
        return this->defense;
    }
    ///Getter for luck
    const int getLuck() const {
        return this->luck;
    }
    ///Getter/setter for armour
    Item & getArmour() {
        return this->armour;
    }
    ///Getter/setter for weapon
    Item & getWeapon() {
        return this->weapon;
    }
    ///Default destructor
    virtual ~Entity() = default;
};
#endif //NHF2_ENTITY_H
