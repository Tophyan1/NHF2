//
// Created by Gyuri on 2019. 04. 12..
//

#include "Monster.h"


void Monster::drop(Player& player, std::mt19937& generator){
    std::uniform_int_distribution<int> disGold (500, 1000);
    int gold = disGold(generator);
    player.getGold() += gold;
    std::cout << "You have received " << gold << " gold." << std::endl;
    std::uniform_int_distribution<int> disType (0, 2);
    int type = disType(generator);

    switch (type){
        case 0:{ //Item is armour
            std::normal_distribution<double> disE (15, 1);
            unsigned int prot = disE(generator);
            unsigned int price = 20 * prot;
            Item drop("Generic Thick Cloth", price, prot, Armour);
            std::cout << "You have received some " << drop.getName() << "." << std::endl;
            if (drop.getEffect() > player.getArmour().getEffect()){
                std::cout << "Seems like Your armour is worse than this rag. Let Me dress You up, You big baby." << std::endl;
                player.getInventory().push_back(player.getArmour());
                player.getArmour() = drop;
            }
            else
                player.getInventory().push_back(drop);
            break;
        }
        case 1:{ //Item is weapon
            std::uniform_int_distribution<int> disN (0, 5);
            std::normal_distribution<double> disE (20, 1);
            std::vector<std::string> weapons = {"Sword", "Axe", "Cleaver", "Mace", "Knife", "Placebo Gun"};
            unsigned int strength = disE(generator);
            unsigned int price = 25 * strength;
            std::string name = weapons[disN(generator)];
            Item drop(name, price, strength, Weapon);
            std::cout << "You have received a(n) " << drop.getName() << "." << std::endl;
            if (drop.getEffect() > player.getWeapon().getEffect()){
                std::cout << "It is more efficient at killing than Your current weapon, so I have taken the courtesy of changing Your main weapon. You are welcome." << std::endl;
                player.getInventory().push_back(player.getWeapon());
                player.getWeapon() = drop;
            }
            else
                player.getInventory().push_back(drop);
            break;
        }
        case 2:{ //Item is potion
            Item drop("Potion", 200, 50, Potion);
            player.getInventory().push_back(drop);
            std::cout << "You have received a potion." << std::endl;
            break;
        }
        default:
            break;
    }
}

