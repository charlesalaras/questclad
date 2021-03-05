#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

class Interface {
public:
  virtual void draw() = 0;
  virtual void undraw() = 0;
  virtual std::string update(int c) = 0;
};

#endif
