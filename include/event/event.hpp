#ifndef EVENT_HPP
#define EVENT_HPP

class EventBus;

class Event {
private:
  EventBus* eventBus;
  bool isActive = true;

protected:
  bool finish();

public:
  Event(EventBus* eventBus);
  
  void run();
  
  bool isActive();

  virtual void draw() = 0;
  virtual void select(char option) = 0;

};

#endif
