
#ifndef NHF2_ITEM_H
#define NHF2_ITEM_H

#include <string>

enum ItemType {
    Armour = 0,
    Weapon = 1,
    Potion = 2
};


class Item {
private:
    std::string name;
    unsigned int price;
    unsigned int effect;
    ItemType type;
public:
    Item(std::string name, unsigned int price = 0, unsigned int effect = 0, ItemType type = Potion) : name(std::move(name)), price(price),
                                                                                    effect(effect), type(type) {}


    const std::string getName() const {
        return this->name;
    }

    unsigned int getPrice() const {
        return this->price;
    }

    unsigned int getEffect() const {
        return this->effect;
    }



    ~Item() = default;


};



#endif //NHF2_ITEM_H
