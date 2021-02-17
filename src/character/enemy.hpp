#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy {
protected:
  string name;
  int gold;

public:
  Enemy(string name, int gold) : name(name), gold(gold) {};

};

#endif
