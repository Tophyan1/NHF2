//
// Created by Gyuri on 2019. 04. 12..
//

#ifndef NHF2_MONSTER_H
#define NHF2_MONSTER_H

#include <random>
#include <chrono>

#include "Entity.h"
#include "Player.h"

/**
 * Monster tha player can defeat
 * */
class Monster : public Entity{
public:
    ///Constructor
    Monster(std::string &name, int hp, unsigned int maxHp, unsigned int strength, unsigned int defense, int luck,
            Item &armour, Item &weapon) : Entity(name, hp, maxHp, strength, defense, luck, armour, weapon) {}


    /// Drops items in players inventory
    /// \param player Player who gets the loot
    /// \param generator Random number generator
    void drop(Player& player, std::mt19937& generator);

    ///Default destructor
    ~Monster() override = default;

};


#endif //NHF2_MONSTER_H
