#include "interface.hpp"

SkillInterface::SkillInterface(vector<Skill*> skills): skillPtr(&skills) {}

void SkillInterface::setProperties(int colorpairs, int rows, int columns) {
   colors = colorpairs;
   introw = rows;
   intcol = columns;
}

int SkillInterface::DrawInt(WINDOW * skillwin) {
   int returnInt = -1;
   for(int i = 0; i < 2; i++) {
      mvwprintw(skillwin, 2*i + 2, (intcol - skillPtr->at(i)->name.size()) / 4, skillPtr->at(i)->name.c_str());
   }
   for(int i = 2; i < 4; i++) {
      mvwprintw(skillwin, 2*i + 2, (intcol - skillPtr->at(i)->name.size() * 3) / 4, skillPtr->at(i)->name.c_str());
   }
}