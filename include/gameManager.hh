#pragma once

#include "screen.hh"

class GameManager {

  public:
  void end();
  void start();

  private:
  Screen scr_helper;
};