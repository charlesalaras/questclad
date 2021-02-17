#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void printTitle(int row, int col);
int printMenu(int row, int col, int argc);

int main(int argc, char** argv) {
    srand(time(NULL));
    // Variables for Initialization + User Input
    int selection = 0;
    int row = 0;
    int col = 0;
    // Preliminary Screen Setup
    initscr(); // Initialize Screen
    curs_set(0); // Hide Cursor
    start_color(); // Start Colors (Maybe Add a Check Before Later On?)
    init_pair(2, COLOR_BLACK, COLOR_CYAN); // Initialize Black Text on Cyan
    getmaxyx(stdscr, row, col); // Get Maximum Space of Window
    noecho(); // Hides Character Echo

    printTitle(row, col); // Prints Questclad (Bright Red on Cyan)
    std::string prompt= "Press [ENTER] to continue.";
    attron(COLOR_PAIR(2)); // Black Text on Cyan
    attron(A_UNDERLINE); // Underline Prompt Text
    mvprintw(row - (row / 4), (col-prompt.size()) / 2, "%s", prompt.c_str());

    while(selection != 10) { // Runs until Enter is Entered
        selection = getch();
    }
    attroff(A_UNDERLINE); // Turn Off Underline
    attroff(COLOR_PAIR(2)); // Turn off Black on Cyan
    selection = printMenu(row, col, argc);
    if(argc > 1) {
        switch(selection) {
            case 0:
                std::cout << "Creating new game...";
                break;
            case 1:
                std::cout << "Loading new game...";
                break;
            case 2:
                std::cout << "Credits rolling...";
                break;
            case 3:
                std::cout << "Quitting game... See you next time!";
                endwin();
                return 0;
        }
    }
    else {
        switch(selection) {
            case 0:
                std::cout << "Creating new game...";
                break;
            case 1:
                std::cout << "Credits rolling...";
                break;
            case 2:
                std::cout << "Quitting game... See you next time!";
                endwin();
                return 0;
        }
    }
    endwin();
    return 0;
}

void printTitle(int row, int col) {
    init_pair(1, COLOR_RED, COLOR_CYAN);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    wbkgd(stdscr, COLOR_PAIR(1));
    std::string line0 = "============================================================================================";
    std::string line1 = "   .oooooo.                                         .             oooo                  .o8 ";
    std::string line2 = "  d8P'  `Y8b                                      .o8             `888                 `888 ";
    std::string line3 = " 888      888    oooo  oooo   .ooooo.   .oooo.o .o888oo  .ooooo.   888   .oooo.    .oooo888 ";
    std::string line4 = " 888      888    `888  `888  d88' `88b d88(  `8   888   d88' ''Y8  888  `P  )88b  d88' `888 ";
    std::string line5 = " 888      888     888   888  888ooo888 ''Y88b.    888   888        888   .oP'888  888   888 ";
    std::string line6 = " `88b    d88b     888   888  888    .o o.  )88b   888 . 888   .o8  888  d8(  888  888   888 ";
    std::string line7 = "  `Y8bood8P'Ybd'  `V88V`V8P' `Y8bod8P' 8''888P'   `888` `Y8bod8P' o888o `Y888``8o `Y8bod88P`";
    attron(A_BOLD);
    mvprintw(1, (col-line0.size()) / 2, "%s", line0.c_str());
    mvprintw(3, (col-line1.size()) / 2, "%s", line1.c_str());
    mvprintw(4, (col-line2.size()) / 2, "%s", line2.c_str());
    mvprintw(5, (col-line3.size()) / 2, "%s", line3.c_str());
    mvprintw(6, (col-line4.size()) / 2, "%s", line4.c_str());
    mvprintw(7, (col-line5.size()) / 2, "%s", line5.c_str());
    mvprintw(8, (col-line6.size()) / 2, "%s", line6.c_str());
    mvprintw(9, (col-line7.size()) / 2, "%s", line7.c_str());
    mvprintw(11, (col-line0.size()) / 2, "%s", line0.c_str());
    attron(COLOR_PAIR(5));
    for(int j = 13; j < 16; j++) {
      for(int i = 0; i < col; i++) {
         if(rand() % 100 < 15) {
            attron(COLOR_PAIR(5));
            attron(A_BOLD);
            if(i + 6 > col) {
               continue;
            }
            mvprintw(j, i, " ~  ~ ");
            attroff(COLOR_PAIR(5));
            attroff(A_BOLD);
         }
      }
    }
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(4));
    for(int j = 2; j > 0; j--) {
      for(int i = 0; i < col; i++) {
         if(rand() % 100 > 65) {
            mvprintw(row - j, i, "^");
         }
         else {
            mvprintw(row - j, i, " ");
         }
      }
    }
    attroff(COLOR_PAIR(4));
    refresh();
}

int printMenu(int row, int col, int argc) {
    int returnOption = -1;
    int userInput = 0;
    int menuRows;
    int optionSize;
    std::string choices[4] = {"Create Game", "Load Game", "Credits", "Quit Game"};
    if(argc > 1) {
        menuRows = 11;
        optionSize = 4;
    }
    else {
        menuRows = 9;
        choices[1] = "Credits";
        choices[2] = "Quit Game";
        optionSize = 3;
    }
    int menuColumns = col / 2;
    int highlight = 0;
    // Window Initialization
    init_pair(3, COLOR_WHITE, COLOR_BLACK); // Initialize White Text on Black
    WINDOW * choicewin = newwin(menuRows, menuColumns, row - row / 2, col / 4);
    wbkgd(choicewin, COLOR_PAIR(3));
    // Window Drawing
    box(choicewin, 0, 0);
    mvwprintw(choicewin, 0, 2, "[ Move with Arrow Keys, Choose with Enter ]");
    wrefresh(choicewin); // Activate Changes
    // Keypad Enable
    keypad(choicewin, true);

    while(1) {
        for(int i = 0; i < optionSize; i++) {
            if(i == highlight) {
                wattron(choicewin, A_REVERSE);
            }
                mvwprintw(choicewin, i + (2 + i), (menuColumns - choices[i].size()) / 2, choices[i].c_str());
                wattroff(choicewin, A_REVERSE);
        }
        userInput = wgetch(choicewin);
        switch(userInput) {
            case KEY_UP:
                highlight--;
                if(highlight == -1) {
                    highlight = optionSize - 1;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == optionSize) {
                    highlight = 0;
                }
                break;
            default:
                break;
        }
        if(userInput == 10) {
            returnOption = highlight;
            break;
        }
    }
    return returnOption;
}
