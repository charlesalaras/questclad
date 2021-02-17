#ifndef DAMAGEABLE_HPP
#define DAMAGEABLE_HPP

class Damageable {
private:
  int health;
  int defense;
  int strength;

public:
  bool isAlive() {
    return this->health > 0;
  }

  void takeDamage(int damage) {
    this->health -= damage;
  }

  virtual void attack(Damageable target) = 0;

};

#endif
