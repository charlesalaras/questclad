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
    int classtype;
public:
    User(std::string name, int classtype);
    ~User();
    std::string getAttack(int index);
    int getItemType(int index);
    void giveGold(int bonus) { gold += bonus; }
    void useItem(int index);
    void setArmor(Item* armor);
    void setWeapon(Item* weapon);
    void removeItem(Item* consumable);
}
