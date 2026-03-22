// Project headers
#include "menuScreen.hh"
#include "screen.hh"

// External headers
#include <ncurses.h>

// Constructor
MenuScreen::MenuScreen(Screen& scr) : scr_helper(scr){
  initScreen();
}
// Destructor
MenuScreen::~MenuScreen() {
  closeScreen();
}

// Public

int MenuScreen::run() {
  int y = 21, x = 26, ch;
  while (true) {
    werase(m_win);
    scr_helper.insertText(m_win, banner, 10, 5, false);
    scr_helper.insertText(m_win, options, 30, 20, true);
    scr_helper.highlightLine(m_win, y);
    mvwprintw(m_win, y, x, "->");

    box(m_win, 0, 0);

    wrefresh(m_win);
    ch = getch();
    switch(ch) {
      case KEY_UP:
        if (y > 21) { y -= 2; }
        break;
      case KEY_DOWN:
        if (y < 25) { y += 2; }
        break;
      case 10:
        if (y == 21) { return 0; }
        else if (y == 23) { return 1; }
        else if (y == 25) { return 2; }
    }
  }
}

// Private

void MenuScreen::initScreen() {
  m_win = scr_helper.newWindow(40, 80);
  werase(m_win);
}

void MenuScreen::closeScreen() {
  scr_helper.closeWindow(m_win);
}