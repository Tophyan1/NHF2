#include <sstream>
#include <fstream>
#include <string>
#include <memory>

#include "Game.h"


void Game::battle() {

    std::uniform_int_distribution<int> dis (0, this->player.getLuck());

    while (this->player.getHp() > 0 && this->tile.getMonster().getHp() > 0) {

        int playerAttack = player.getStrength() + player.getWeapon().getEffect() + dis(generator) - tile.getMonster().getDefense();
        int monsterAttack = tile.getMonster().getStrength() - player.getDefense() - player.getArmour().getEffect();

        this->tile.getMonster().getHp() -= playerAttack;
        std::cout << "You have inflicted " << playerAttack << " damage." << std::endl;
        if (tile.getMonster().getHp() <= 0)
            break;

        player.getHp() -= monsterAttack;
        std::cout << "You have received  " << monsterAttack << " damage." << std::endl;
    }
    if (player.getHp() <= 0){
        std::cout << "You have died. What a shame. Time for a new test subj- I mean, hero..." << std::endl;
        exit(0);
    }
    else {
        std::cout << "You have won and killed this creature. Now tell Me, who is the monster now?" << std::endl;
        tile.getMonster().drop(player, generator);
    }

}



void Game::forward() {
    std::ifstream fin;
    fin.open("adventure.txt");
    std::string line;
    do {
        std::getline(fin, line);
    }
    while (line != this->tile.getStory());

    std::getline(fin, line);
    if (line == "SHOP") {
        std::vector<Item> shopInventory;
        for (int i = 0; i < 3; ++i)
            shopInventory.emplace_back(Item("Potion", 200, 30));
        std::getline(fin, line);
        this->tile = Tile(line, shopInventory);

    }
    else if (line == "MONSTER") {
        std::getline(fin, line);
        Item hand("Hand", 0, 0, Weapon), skin("Skin", 0, 0, Armour);
        std::string monsterName = "Scary Monster";
        auto newMonster = std::make_shared<Monster>(monsterName, 100, 100, 25, 10, 0, skin, hand);
        this->tile = Tile(line, newMonster);
    }
    else if (line == "NULL") {
        std::getline(fin, line);
        this->tile = Tile(line);
    }
    else {
        std::cout << "End path runs" << std::endl;
        std::cout << "Wow. You have completed the test run. I guess You are a hero after all. Or a lucky bastard. "
                     "Anyways, I can't get You a trophy, if You are waiting for that, so please, just go. "
                     "I have made so that no matter what You enter, the game is over. Have a nice rest of the day!" << std::endl;
        std::string lastWord;
        std::cin >> lastWord;
        fin.close();
        exit(0);
    }
    fin.close();

    this->tile.tellStory();
}

void Game::getHelp() const {
    std::cout << "How can You not know the commands? They are easy, listen:\n"
                 "\tYou can ask for [help].\n"
                 "\tYou can [attack] an enemy, if there's one.\n"
                 "\tYou can ask to be reminded of the [story]\n"
                 "\tYou can [buy ...] from or [sell ...] to a shop, if You come across one\n"
                 "\tYou can [list] Your inventory, also that of a [shop].\n"
                 "\tYou can [drink] a potion, if You want to.\n"
                 "\tYou can look at Your [stats] if You fancy that.\n"
                 "\tYou can [go] forward, if You just can't stay in one place for extended periods of time.\n"
                 "\tFinally, You can [exit] the game, if You wish to stop having fun." << std::endl;
}

void Game::play(){

    std::ifstream fin;
    fin.open("adventure.txt");
    if (!fin.is_open()) {
        std::cerr << "File could not be opened. What a shame.";
    }
    std::string line;
    std::getline(fin, line);
    std::cout << line;
    this->tile = Tile(line);
    fin.close();

    std::cout << "Welcome, hero!\n"
                 "Congratulations on being one! This is Your chance to prove that You are not in fact worthless." << std::endl;

    this->player.askName();
    this->tile.tellStory();
    std::string command;
    do {
        std::cout << ">";
        std::getline(std::cin, command);
        if (std::regex_match(command, std::regex("(help|help +.*)", std::regex::icase))) {
            this->getHelp();
        }
        else if (std::regex_match(command, std::regex("(attack|attack +.*)", std::regex::icase))) {
            if ((this->tile.ptrToMonster() != nullptr)){
                if (this->tile.getMonster().getHp() <= 0) {
                    std::cout << "Would You really attack a dead creature? Are You sure You are a hero?" << std::endl;
                    continue;
                }
                this->battle();
            }
            else {
                std::cout << "There's no monster for You to attack, You bloodthirsty madman." << std::endl;
            }
        }
        else if (std::regex_match(command, std::regex("(story|story +.*)", std::regex::icase))) {
            this->tile.tellStory();
        }
        else if (std::regex_match(command, std::regex("(list|list +.*)", std::regex::icase))) {
            this->player.listInventory();
        }
        else if (std::regex_match(command, std::regex("(stats|stats +.*)", std::regex::icase))) {
            this->player.stats();
        }
        else if (std::regex_match(command, std::regex("(drink|drink +.*)", std::regex::icase))) {
            this->player.drink();
        }
        else if (std::regex_match(command, std::regex("(shop|shop +.*)", std::regex::icase))) {
            this->tile.listItems();
        }
        else if (std::regex_match(command, std::regex("(buy|buy +.*)", std::regex::icase))) {
            this->tile.sell(this->player);
        }
        else if (std::regex_match(command, std::regex("sell +.+", std::regex::icase))) {
            std::string itemName = command.substr(command.find_first_not_of(' ', 4), 100);
            std::cout << itemName << "|" << std::endl;
            this->tile.buy(this->player, itemName);
        }
        else if (std::regex_match(command, std::regex("(go|go +.*)", std::regex::icase))) {
            this->forward();
        }
    }
    while (!std::regex_match(command, std::regex("(exit|exit +.*)", std::regex::icase)));

    std::cout << "You have exited the game. I wanted to play, but You surely have something better to do. Well, then. Goodbye!" << std::endl;

}
