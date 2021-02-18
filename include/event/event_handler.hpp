#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

class EventBus;
//class Interface;

class EventHandler {
private:
  EventBus* eventBus;
  bool isActive = true;

protected:
  bool finish();

public:
  EventHandler(EventBus* eventBus);
  
  void run(std::string message);
  
  bool isActive();

  virtual void draw() = 0;
  virtual void select(char option) = 0;

};

#endif
