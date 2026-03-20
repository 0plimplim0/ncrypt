#include "gameManager.hh"
#include "screen.hh"
#include "cryptogram.hh"

#include <ncurses.h>
#include <unordered_map>

int GameManager::mainMenuScreen(Screen& scr) {
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

void GameManager::playScreen(Screen& scr) {
  auto* win = scr.newWindow(40, 80);
  werase(win);

  // Variables
  std::string phrase = "this is a test";
  std::unordered_map<char, int> umap;
  Cryptogram::generateMap(umap);
  int x = 1;
  for (char c : phrase) {
    int ch = umap[c];
    if (ch != 0) {
      mvwprintw(win, 1, x, "_");
      mvwprintw(win, 2, x, "%d ", ch);
    } else {
      mvwprintw(win, 2, x, "  ");
    }
    if (ch > 9) { x += 3; }
    else { x += 2; }
  }

  box(win, 0, 0);
  wrefresh(win);
  getch();
  scr.closeWindow(win);
}

void GameManager::leaderboardScreen(Screen& scr) {
  auto* win = scr.newWindow(40, 80);
  werase(win);
  mvwprintw(win, 1, 1, "Leaderboard screen");
  box(win, 0, 0);
  wrefresh(win);
  getch();
  scr.closeWindow(win);
}