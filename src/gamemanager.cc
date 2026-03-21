#include "gameManager.hh"
#include "screen.hh"
#include "cryptogram.hh"

#include <ncurses.h>
#include <unordered_map>

// This class is supposed to instanciate Screen and do Screen::initScreen

// TODO: Remove this and make class MenuScreen
int GameManager::menuScreen(Screen& scr) {
  auto* win = scr.newWindow(40, 80);
  int y = 21, x = 26, ch;
  while(true) {
    werase(win);
    scr.insertText(win, banner, 10, 5, false);
    scr.insertText(win, options, 30, 20, true);
    scr.highlightLine(win, y);
    mvwprintw(win, y, x, "->");

    box(win, 0, 0);

    wrefresh(win);
    ch = getch();
    switch(ch) {
      case KEY_UP:
        if (y > 21) { y -= 2; }
        break;
      case KEY_DOWN:
        if (y < 25) { y += 2; }
        break;
      case 10:
        if (y == 21) { scr.closeWindow(win); return 0; }
        else if (y == 23) { scr.closeWindow(win); return 1; }
        else if (y == 25) { scr.closeWindow(win); return 2; }
    }
  }
}