#include <ncurses.h>

class Screen {
  public:
  void initScreen();
  void closeScreen();
  WINDOW* newWindow(int height, int width);
  void closeWindow(WINDOW* w);
  void insertText(WINDOW* w, const char* text, int x, int y, bool emptyLines);
};