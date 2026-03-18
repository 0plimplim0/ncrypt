#include <ncurses.h>

class Screen {
  public:
  void initScreen();
  void closeScreen();
  int mainMenu();

  private:
  void showBanner(WINDOW* w, int x, int y);
  void showOptions(WINDOW* w, int x, int y);
  void handlePos(WINDOW* w, int y);
};