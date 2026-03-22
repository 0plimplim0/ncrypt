// Project headers
#include "screen.hh"
#include "gameManager.hh"
#include "playScreen.hh"
#include "leaderboardScreen.hh"
#include "menuScreen.hh"

// External headers
#include <ncurses.h>

int main() {

  // Init process
  Screen screen;
  screen.initScreen();
  refresh();

  PlayScreen pScreen(screen);
  LeaderboardScreen lScreen(screen);
  MenuScreen mScreen(screen);

  enum Screens {
    play,
    leaderboard,
    exit
  };
  
  bool running = true;
  while (running) {
    int selection = mScreen.run();
    
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
  // TODO: Move this to the destructor of Screen
  screen.closeScreen();
  return 0;
}