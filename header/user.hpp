#include"damageable.hpp"
#include<vector>

class User: public Damageable{

public:
    int level;
    vector<Skill*> skills;
    vector<Item*> item;
    UserInterface ui;
    int classtype;

    User() {}

}
