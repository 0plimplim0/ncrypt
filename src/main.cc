#include "screen.hh"

#include <ncurses.h>

// Just for testing:/
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
const char* options = R"(
1. P L A Y

2. L E A D E R B O A R D

3. E X I T
)";

int main() {

  // Init process
  Screen screen;
  screen.initScreen();

  auto* win = screen.newWindow(40, 80);
  box(win, 0, 0);

  screen.insertText(win, banner, 10, 5, false);
  screen.insertText(win, options, 30, 20, true);

  wrefresh(win);
  getch();

  // Close process
  screen.closeWindow(win);
  screen.closeScreen();
  return 0;
}