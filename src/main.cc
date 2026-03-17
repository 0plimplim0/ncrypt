#include "screen.hh"

#include <ncurses.h>

int main() {

  Screen screen;
  screen.initScreen();

  bool running = true;

  while (running) {
    int selection = screen.mainMenu();

    switch (selection) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        running = false;
        break; 
    }
  }

  screen.closeScreen();
  return 0;
}