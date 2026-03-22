// Project headers
#include "leaderboardScreen.hh"
#include "screen.hh"

// External headers
#include <ncurses.h>

// Constructor
LeaderboardScreen::LeaderboardScreen(Screen& scr) : scr_helper(scr) {
  initScreen();
}

// Destructor
LeaderboardScreen::~LeaderboardScreen() {
  closeScreen();
}

// Public

void LeaderboardScreen::run() {
  mvwprintw(m_win, 1, 1, "LeaderboardScreen class test");
  box(m_win, 0, 0);
  wrefresh(m_win);
  getch();
}

// Private

void LeaderboardScreen::initScreen() {
  m_win = scr_helper.newWindow(40, 80);
  werase(m_win);
}

void LeaderboardScreen::closeScreen() {
  scr_helper.closeWindow(m_win);
}