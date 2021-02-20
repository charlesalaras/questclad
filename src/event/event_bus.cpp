#include "event_bus.hpp"
#include "event_handler.hpp"

void EventBus::dispatch(std::string event, std::string message) {
  for(auto handler : this->map[event]) {  
    handler->run(message);
  }
}

void EventBus::register(std::string event, EventHandler* handler) {
  //using this->map[event] will default construct a vector if there is none
  this->map[event].push_back(handler); 
}
