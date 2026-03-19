#pragma once

#include "screen.hh"

class GameManager {

  public:
  int mainMenuScreen(Screen& scr);
  void playScreen(Screen& scr);
  void leaderboardScreen(Screen& scr);

  private:
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