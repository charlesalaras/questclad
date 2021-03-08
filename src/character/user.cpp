#include"user.hpp"

User::User(std::string name, int classtype) {}
std::string User::getAttack(int index) {}
std::string User::getItemType(int index) {}
void User::useItem(int index) {
   // VISITOR PATTERN
   /*
   In this scenario, we need to apply a bonus to user, but we don't know what kind.
   The visitor pattern works by making User itself a visitor to the item, and the
   item telling the visitor what kind of function it should call on itself in order
   to apply changes to its own local variables
   */
   inventory.at(index)->accept(this);
}
int User::attack(Damageable* target) {}