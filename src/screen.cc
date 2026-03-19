#include "screen.hh"
#include <ncurses.h>
#include <string>
#include <sstream>

void Screen::initScreen() {
  initscr();
  noecho();
  curs_set(0);
  cbreak();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
}

void Screen::closeScreen() {
  endwin();
}

// TODO: Add position enum for more layouts support
WINDOW* Screen::newWindow(int height, int width) {
  int r, c;
  getmaxyx(stdscr, r, c);
  // do refresh() after call this func
  WINDOW *win = newwin(height, width, (r/2)-(height/2), (c/2)-(width/2));
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

void Screen::highlightLine(WINDOW* w, int y) {
  int width = getmaxx(w);
  mvwchgat(w, y, 0, width, A_BOLD, 1, NULL);
}