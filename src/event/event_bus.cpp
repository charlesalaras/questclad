#include "event_bus.hpp"
#include "event.hpp"


Event EventBus::getNext() {
  Event next = this->bus.front();
  this->bus.pop_front();
  return next;
}

void EventBus::register(Event event) {
  this->bus.push_back(event);
}

void EventBus::registerImmediate(Event event) {
  this->bus.push_front(event);
}

void setTrigget(Event event, int turns) {
  //todo

}
