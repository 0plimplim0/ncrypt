// Project headers
#include "screen.hh"
#include "gameManager.hh"
#include "playScreen.hh"
#include "leaderboardScreen.hh"

// External headers
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
    int selection = gm.menuScreen(screen);

    PlayScreen pScreen(screen);
    LeaderboardScreen lScreen(screen);
    
    switch (selection) {
      case play:
        pScreen.run();
        break;
      case leaderboard:
        lScreen.run();
        break;
      case exit:
        running = false;
    }
  }

  // Close process
  screen.closeScreen();
  return 0;
}