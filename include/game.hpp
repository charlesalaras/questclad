#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "event/event_bus.hpp"
#include "event/event.hpp"
#include "character/user.hpp"

#include <ncurses.h>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>

class Game {
private:
   std::string saveName;
   EventBus events;
   std::vector<std::string>storyElements;
   User* mainCharacter = nullptr;
   bool loadGame(); // Helper to Parametrized Constructor
   std::string getName();
   void endScreen();
   WINDOW* instanceWin;
public:
   Game();
   Game(std::string fname); // Calls loadGame
   ~Game();
   void build();
   void runGame();
   void saveGame();
   bool passingPrompt();
   void finishGame();
};

#endif //__GAME_HPP__
