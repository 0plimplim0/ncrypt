// Project headers
#include "playScreen.hh"
#include "screen.hh"

// External headers
#include <ncurses.h>
#include <unordered_map>

// Constrctor
PlayScreen::PlayScreen(Screen& scr) : scr_helper(scr) {
  initScreen();
}

// Destructor
PlayScreen::~PlayScreen() {
  closeScreen();
}

// Public

void PlayScreen::run() {
  mvwprintw(m_win, 1, 1, "PlayScreen class test");
  box(m_win, 0, 0);
  wrefresh(m_win);
  getch();
}

// Private

void PlayScreen::initScreen() {
  // height and width are hardcoded bc all GameScreens supposed to be the same size
  // TODO: change that bc only works if the terminal size is bigger than 80x40
  m_win = scr_helper.newWindow(40, 80);
  werase(m_win);
}

void PlayScreen::closeScreen() {
  scr_helper.closeWindow(m_win);
}