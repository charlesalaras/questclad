#ifndef DAMAGEABLE_HPP
#define DAMAGEABLE_HPP

class Damageable {
private:
  int health;
  int defense;
  int strength;

public:
  bool isAlive();

  void takeDamage(int damage);

  virtual void attack(Damageable* target) = 0;

};

#endif
