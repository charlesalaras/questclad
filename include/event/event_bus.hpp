#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <unordered_map>
#include <vector>

class EventHandler;

class EventBus {
private:
  std::unordered_map<std::string, std::vector<EventHandler*>> map;

public:
  EventBus();
  void register(std::string event, EventHandler* handler);

};

#endif
