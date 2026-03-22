#pragma once

// Project headers
#include "screen.hh"

// External headers
#include <ncurses.h>

class MenuScreen {
  public:
    MenuScreen(Screen& scr);
    ~MenuScreen();
    int run();
  private:
    void initScreen();
    void closeScreen();
    WINDOW* m_win = nullptr;
    Screen& scr_helper;
    const char* banner = R"(
             $$$$$$\                                 $$\
            $$  __$$\                                $$ |
  $$$$$$$\  $$ /  \__| $$$$$$\  $$\   $$\  $$$$$$\ $$$$$$\
  $$  __$$\ $$ |      $$  __$$\ $$ |  $$ |$$  __$$\\_$$  _|
  $$ |  $$ |$$ |      $$ |  \__|$$ |  $$ |$$ /  $$ | $$ |
  $$ |  $$ |$$ |  $$\ $$ |      $$ |  $$ |$$ |  $$ | $$ |$$\
  $$ |  $$ |\$$$$$$  |$$ |      \$$$$$$$ |$$$$$$$  | \$$$$  |
  \__|  \__| \______/ \__|       \____$$ |$$  ____/   \____/
                                $$\   $$ |$$ |
                                \$$$$$$  |$$ |
                                 \______/ \__|
  )";
  const char* options = R"(
  1. P L A Y

  2. L E A D E R B O A R D

  3. E X I T
  )";
};