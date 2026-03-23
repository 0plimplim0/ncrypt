// Project headers
#include "gameManager.hh"
#include "screen.hh"
#include "menuScreen.hh"
#include "playScreen.hh"
#include "leaderboardScreen.hh"

// External headers
#include <ncurses.h>
#include <unordered_map>

// Public

void GameManager::end() {
  scr_helper.closeScreen();
}

void GameManager::start() {

  scr_helper.initScreen();
  refresh();

  MenuScreen mScreen(scr_helper);
  PlayScreen pScreen(scr_helper);
  LeaderboardScreen lScreen(scr_helper);

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
}