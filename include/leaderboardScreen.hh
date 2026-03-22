#pragma once

// Project headers
#include "screen.hh"

// External headers
#include <ncurses.h>

class LeaderboardScreen {
  public:
    LeaderboardScreen(Screen& scr);
    ~LeaderboardScreen();
    void run();
  private:
    void initScreen();
    void closeScreen();
    WINDOW* m_win = nullptr;
    Screen& scr_helper;
};