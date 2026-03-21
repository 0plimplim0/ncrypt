#pragma once

// Project headers
#include "screen.hh"

// External headers
#include <ncurses.h>

class LeaderboardScreen {
  public:
    LeaderboardScreen(Screen& scr);
    ~LeaderboardScreen();
    void initScreen();
    void closeScreen();
    void run();
  
  private:
    WINDOW* m_win = nullptr;
    Screen& scr_helper;
};