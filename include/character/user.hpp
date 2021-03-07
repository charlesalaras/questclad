#include"damageable.hpp"
#include<vector>

class User: public Damageable{

private:
    int level;
    vector<Skill*> skills;
    vector<Item*> item;
    UserInterface ui;
    int classtype;
public:
    User(std::string name, int classtype);
    std::string getAttack(int index);
    std::string getItemType(int index);
    void giveGold(int bonus) { gold += bonus; }
    int attack(Damageable* target); // Does Calculations and Returns Them for Damage Dealt

}
