#include "screen.hh"
#include <ncurses.h>
#include <string>
#include <sstream>

void Screen::initScreen() {
  initscr();
  noecho();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
}

void Screen::closeScreen() {
  endwin();
}

WINDOW* Screen::newWindow(int height, int width) {
  int r, c;
  getmaxyx(stdscr, r, c);
  WINDOW *win = subwin(stdscr, height, width, (r/2)-(height/2), (c/2)-(width/2));
  return win;
}

void Screen::closeWindow(WINDOW* w) {
  delwin(w);
}

void Screen::insertText(WINDOW* w, const char* text, int x, int y, bool emptyLines) {
  std::stringstream ss(text);
  std::string line;
  while (std::getline(ss, line)) {
    if (emptyLines) {
      mvwprintw(w, y++, x, "%s", line.c_str());
    } else {
      if (!line.empty()) {
        mvwprintw(w, y++, x, "%s", line.c_str());
      }
    }
  }
}