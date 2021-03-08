#include"damageable.hpp"
#include<vector>
#include <pair>

class User: public Damageable{

private:
    int level;
    int currentArmor;
    int currentWeapon;
    vector<Skill*> skills;
    vector<Item*> inventory;
    UserInterface ui;
    int classtype;
public:
    User(std::string name, int classtype);
    std::string getAttack(int index);
    std::string getItemType(int index);
    void giveGold(int bonus) { gold += bonus; }
    void useItem(int index);
    int attack(Damageable* target); // Does Calculations and Returns Them for Damage Dealt
    void setArmor(Item* armor);
    void setWeapon(Item* weapon);
    void removeItem(Item* consumable);
    std::pair<int, int> getChoice() { return ui->drawInt() };
}
