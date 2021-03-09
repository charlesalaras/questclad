#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

class Interface {
public:
  virtual void draw() = 0;
  virtual int update(int c) = 0;
};

#endif
