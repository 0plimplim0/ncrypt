#include "screen.hh"
#include <ncurses.h>
#include <string>
#include <sstream>

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
  int ptr_x = 24, ptr_y = 18;
  int ch;

  int f, c;
  getmaxyx(stdscr, f, c);

  WINDOW *sub = subwin(stdscr, 40, 80, (f/2)-20, (c/2)-40);

  while (true) {
    werase(sub);

    showBanner(sub, 10, 3);
    showOptions(sub, 20, 17);
    handlePos(sub, ptr_y);
    mvwprintw(sub, ptr_y, ptr_x, "->");
    box(sub, 0, 0);

    wrefresh(sub);

    ch = getch();

    switch (ch) {
      case KEY_UP:
        if (ptr_y > 18) { ptr_y -= 2; }
        break;
      case KEY_DOWN:
        if (ptr_y < 22) { ptr_y += 2; }
        break; 
      case 10:
        if (ptr_y == 18) { return 1; }
        else if (ptr_y == 20) { return 2; }
        else if (ptr_y == 22) { delwin(sub); return 3; }
    }
  }
}

// Private
void Screen::showBanner(WINDOW* w, int x, int y) {
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
  std::stringstream ss(banner);
  std::string line;
  int current_y = y;

  while (std::getline(ss, line)) {
    if (!line.empty()) {
      mvwprintw(w, current_y++, x, "%s", line.c_str());
    }
  }
}

void Screen::showOptions(WINDOW* w, int x, int y) {
  const char* options = R"(
          1. P L A Y

          2. L E A D E R B O A R D

          3. E X I T
  )";
  std::stringstream ss(options);
  std::string line;
  int current_y = y;

  while (std::getline(ss, line)) {
    mvwprintw(w, current_y++, x, "%s", line.c_str());
  }
}

void Screen::handlePos(WINDOW* w, int y) {
  if (y == 18) mvwchgat(w, 18, 30, 37, A_BOLD, 1, NULL);
  else if (y == 20) mvwchgat(w, 20, 30, 44, A_BOLD, 1, NULL);
  else if (y == 22) mvwchgat(w, 22, 30, 37, A_BOLD, 1, NULL);
}

// TODO: refactor ts bc is hardcoded trashhhh