#include "event/event_bus.hpp"

EventBus::EventBus() { }

EventBus::~EventBus() {
   while(hasNext()) {
      delete getNext();
   }
}

bool EventBus::hasNext() {
  return !this->bus.empty();
}

Event* EventBus::getNext() {
  Event* next = this->bus.front();
  this->bus.pop_front();
  return next;
}

void EventBus::registerEvent(Event* event) {
  this->bus.push_back(event);
}

void EventBus::registerImmediate(Event* event) {
  this->bus.push_front(event);
}

void setTrigger(Event* event, int turns) {
  //todo

}
