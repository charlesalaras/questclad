#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <list>
#include <utility>

#include "event/event.hpp"

class EventBus {
private:
  std::list<Event*> bus;
  std::list<std::pair<int, Event*>> triggers;

public:
  EventBus();
  ~EventBus();
  bool hasNext();
  Event* getNext();
  void registerEvent(Event* event);
  void registerImmediate(Event* event);
  void setTrigger(Event* event, int turns);
};

#endif
