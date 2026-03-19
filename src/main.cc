#include "screen.hh"
#include "gameManager.hh"

#include <ncurses.h>

int main() {

  // Init process
  Screen screen;
  screen.initScreen();
  refresh();

  enum Screens {
    play,
    leaderboard,
    exit
  };
  
  bool running = true;
  GameManager gm;
  while (running) {
    int selection = gm.mainMenuScreen(screen);
    
    switch (selection) {
      case play:
        gm.playScreen(screen);
        break;
      case leaderboard:
        gm.leaderboardScreen(screen);
        break;
      case exit:
        running = false;
    }
  }

  // Close process
  screen.closeScreen();
  return 0;
}