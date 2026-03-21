#pragma once

// Project headers
#include "screen.hh"

// External headers
#include <ncurses.h>

class PlayScreen {
  public:
    PlayScreen(Screen& scr);
    ~PlayScreen();
    void initScreen();
    void closeScreen();
    void run();

  private:
    WINDOW* m_win = nullptr;
    Screen& scr_helper;
};
