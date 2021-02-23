#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <list>
#include <pair>

class Event;

class EventBus {
private:
  std::list<Event> events;
  std::list<std::pair<int, Event>> triggers;

public:
  EventBus();
  
  Event getNext();
  void register(Event event);
  void registerImmediate(Event event);
  void setTrigger(Event event, int turns);
};

#endif
