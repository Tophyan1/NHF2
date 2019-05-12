//
// Created by Gyuri on 2019. 04. 12..
//

#ifndef NHF2_MONSTER_H
#define NHF2_MONSTER_H

#include <random>
#include <chrono>

#include "Entity.h"
#include "Player.h"

class Monster : public Entity{
public:

    Monster(std::string &name, int hp, unsigned int maxHp, unsigned int strength, unsigned int defense, int luck,
            Item &armour, Item &weapon) : Entity(name, hp, maxHp, strength, defense, luck, armour, weapon) {}



    void drop(Player& player, std::mt19937& generator);

    ~Monster() override = default;

};


#endif //NHF2_MONSTER_H
