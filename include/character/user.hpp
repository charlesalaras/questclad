#ifndef USER_HPP
#define USER_HPP

#include "character/damageable.hpp"
#include "character/item.hpp"
#include "character/skill.hpp"
#include <vector>

class Item;
class Skill;

class User: public Damageable{

private:
    int level;
    int currentArmor;
    int currentWeapon;
    std::vector<Skill*> skills;
    std::vector<Item*> inventory;
    int classtype;

public:
    User(std::string name, int classtype);
    ~User();
    std::string getAttack(int index);
    int getItemType(int index);
    std::vector<Skill*> getSkills();
    std::vector<Item*> getItems();
    void useItem(int index);
    void setArmor(Item* armor);
    void setWeapon(Item* weapon);
    void removeItem(Item* consumable);
};

#endif
