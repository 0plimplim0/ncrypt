#include "screen.hh"
#include <ncurses.h>

// Public
void Screen::initScreen() {
  initscr();
  start_color();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
}

void Screen::closeScreen() {
  endwin();
}

int Screen::mainMenu() {
  clear();
  int y = 13, x = 16;
  int ch = 0;

  while (true){
    erase();
    showBanner();
    showOptions();

    handlePos(y);

    mvprintw(y, x, "<-");
    refresh();

    ch = getch();

    switch (ch) {
      case KEY_UP:
        if (y > 13) y--;
        break;
      case KEY_DOWN:
        if (y < 15) y++;
        break;
      case 10:
        if (y == 13) return 1;
        else if (y == 14) return 2;
        else if (y == 15) return 3;
    }
  }
}

// Private
void Screen::showBanner() {
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
  mvprintw(0, 0, "%s", banner);
}

void Screen::showOptions() {
  mvprintw(13, 0, "1. Play");
  mvprintw(14, 0, "2. Leaderboard");
  mvprintw(15, 0, "3. Exit");
}

void Screen::handlePos(int y) {
  if (y == 13) mvchgat(13, 0, 7, A_BOLD, 1, NULL);
  else if (y == 14) mvchgat(14, 0, 14, A_BOLD, 1, NULL);
  else if (y == 15) mvchgat(15, 0, 7, A_BOLD, 1, NULL);
}