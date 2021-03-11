#ifndef EVENT_HPP
#define EVENT_HPP

class EventBus;

class Event {
private:
  bool active = true;

protected:
  void finish() {
    active = false;
  }

public:
  virtual ~Event() {}
  bool isActive() {
    return active;
  }

  virtual void draw() = 0;
  virtual void select(int option) = 0;

};

#endif
