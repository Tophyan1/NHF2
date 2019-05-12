
#ifndef NHF2_ITEM_H
#define NHF2_ITEM_H

#include <string>

/**
 * Enum of type of item
 * Can be Potion, Armour, Weapon
 * */
enum ItemType {
    Armour = 0,
    Weapon = 1,
    Potion = 2
};

/**
 * Class for items the Player can possess
 * */
class Item {
private:
    ///Name of the item
    std::string name;
    ///Price of the item
    unsigned int price;
    /// Effect (depends on type)
    unsigned int effect;
    ///Type of item
    ItemType type;

public:
    ///Constructor
    Item(std::string name, unsigned int price = 0, unsigned int effect = 0, ItemType type = Potion) : name(std::move(name)), price(price),
                                                                                    effect(effect), type(type) {}

    ///Getter for name
    const std::string getName() const {
        return this->name;
    }
    ///Getter for price
    unsigned int getPrice() const {
        return this->price;
    }
    ///Getter for Effect
    unsigned int getEffect() const {
        return this->effect;
    }
    ///Default destructor
    ~Item() = default;

};



#endif //NHF2_ITEM_H
