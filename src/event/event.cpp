#include "event/event_handler.hpp"
#include "event/event_bus.hpp"

EventHandler::EventHandler(EventBus* eventBus) : eventBus(eventBus) { }

void run() {
  this->draw();
  while(this->isActive()) {
    //ncurses get char
    //call this->select()
  }
}
