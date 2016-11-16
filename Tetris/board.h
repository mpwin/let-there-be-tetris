#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

class Board {
public:
  Board();
  void draw();

private:
  int width, height;
  Tile **tiles;
};

#endif
