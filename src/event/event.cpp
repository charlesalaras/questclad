#include "event/event.hpp"
#include "event/event_bus.hpp"
/*
getch() is used intuitively as a buffer throughout the run() function.
This is because if getch is not used, whatever is drawn to screen will
immediately disappear. This also gives the benefit that the user can
advance an event at their own pace, but does create risk of being
infinitely stuck in a state of waiting (which could produce some scary bug)
For now, we presume that if any key is entered, let's advance through.
*/
Event::Event(User* maincharacter, string input, int enemies)
: user(maincharacter), enemyNumber(enemies)
{
   getmaxyx(stdscr, row, col);
   eventBox = newwin(row / 2, col, 0, 0);
   if(input == "Mountain") {
      // Build Mountain Enemmies
      enemyFactory = new MountainFactory();
      
   }
   if(input == "Cavern") {
      // Build Cavern Enemies
      enemyFactory = new CavernFactory();
   }
   if(input == "Desert") {
      // Build Desert Enemies
      enemyFactory = new DesertFactory();
   }
}

void Event::run() {
  while(user->getHealth() > 0 && sumEnemiesHealth() > 0) {
   wclear(eventBox);
   box(eventBox, 0, 0); // drawBox
   printHP(); // This will print the enemy HP during passing moments
   wrefresh(eventBox);
   refresh();
   std::pair<int, int> choice = user->getChoice(); // Get Choice from User
   if(choice->first == 0) { // Attack
      Enemy* target = getAliveEnemy();
      int damageDealt = user->attack(getAliveEnemy(), choice->second); // User should attack whatever enemy it can
      std::string attackText = user->getName() + " dealt " + to_string(damageDealt) + " to " + target->getName() + " using " + user->getAttack(choice->second) + "!";
      mvwprintw(eventBox, row / 2, 2, attackText.c_str());
      wrefresh(eventBox);
      getch();
   }
   if(choice->first == 1) { // Use Consumable
      int boostGiven = user->useItem(choice->second); // Use Item at Specified Index
      std::string boostText = user->getName() + " gained " + to_string(boostGiven) + " boost in " + user->getItemType(choice->second);
      mvwprintw(eventBox, row / 2, 2, boostText.c_str());
      wrefresh(eventBox);
      getch();
   }
   if(choice->first == 2) { // Attempt Escape
      srand(time(NULL));
      if((rand() % 100) < 25) { // User has a 26% chance to escape the event
         std::string runText = user->getName() + " escaped the battle successfully!";
         mvwprintw(eventBox, row / 2, 2, runText.c_str());
         mvwprintw(eventBox, (row / 2) + 1, 2, "Press any key to continue");
         wrefresh(eventBox);
         getch();
         wclear(eventBox);
         return;
      }
   }
   // Enemy Turn
   srand(time(NULL));
   std::string enemyText;
   int damageTaken = 0;
   int enemyAttack = rand() % enemyNumber; // Choose who Attacks for Enemy
   if(enemyAttack == 0) { // Enemy1 Attacks
      damageTaken = enemy1->attack(user, 0);
      enemyText = enemy1->getName() + "strikes for " + to_string(damageTaken) + "damage! " + enemy1->getDialogue + "!";
      mvwprintw(eventBox, row / 2, 2, enemyText.c_str());
      wrefresh(eventBox);
      getch();
   }
   if(enemyAttack == 1) { // Enemy1 Attacks
      damageTaken = enemy2->attack(user, 0);
      enemyText = enemy2->getName() + "strikes for " + to_string(damageTaken) + "damage! " + enemy2->getDialogue + "!";
      mvwprintw(eventBox, row / 2, 2, enemyText.c_str());
      wrefresh(eventBox);
      getch();
   }
   if(enemyAttack == 2) { // Enemy1 Attacks
      damageTaken = enemy3->attack(user, 0);
      enemyText = enemy3->getName() + "strikes for " + to_string(damageTaken) + "damage! " + enemy3->getDialogue + "!";
      mvwprintw(eventBox, row / 2, 2, enemyText.c_str());
      wrefresh(eventBox);
      getch();
   }
  }
  if(user->getHealth() <= 0) {
   wclear(eventBox);
   return;
  }
  else {
   int goldEarned = getEnemyGold();
   std::string successPrompt = "You won! You received " + to_string(goldEarned);
   user->giveGold(goldEarned);
   wclear(eventBox);
   box(eventBox, 0, 0);
   mvwprintw(eventBox, row / 2, 2, successPrompt.c_str());
   wrefresh(eventBox);
  }
}

Enemy* Event::getAliveEnemy() {
   if(enemy1->getHealth() > 0) {
      return enemy1;
   }
   if(enemy2->getHealth() > 0) {
      return enemy2;
   }
   if(enemy3->getHealth() > 0) {
      return enemy3;
   }
   return enemy1;
}

int Event::sumEnemiesHealth() {
   return enemy1->getHealth() + enemy2->getHealth() + enemy3->getHealth();
}

int Event::getEnemyGold() {
   return enemy1->getGold() + enemy2->getGold() + enemy3->getGold();
}

void Event::printHP() {
   std::string health;
   std::string health2;
   std::string health3;
   if(enemyNumber == 3) {
      health = "HP: " + to_string(enemy1->getHealth());
      mvwprintw(eventBox, (row / 2) - 1, col / 3, health);
      health2 = "HP: " + to_string(enemy2->getHealth());
      mvwprintw(eventBox, (row / 2), col / 3, health2);
      health3 = "HP: " + to_string(enemy3->getHealth());
      mvwprintw(eventBox, (row / 2) + 1, col / 3, health3);
   }
   if(enemyNumber == 2) {
      health = "HP: " + to_string(enemy1->getHealth());
      mvwprintw(eventBox, (row / 2), col / 3, health);
      health2 = "HP: " + to_string(enemy2->getHealth());
      mvwprintw(eventBox, (row / 2) - 1, col / 3, health2);
   }
   else {
      health = "HP: " + to_string(enemy1->getHealth());
      mvwprintw(eventBox, row / 2, col / 3, health);
   }
   wrefresh(eventBox);
}
