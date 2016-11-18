#ifndef BOARD_H
#define BOARD_H

#include "tetromino.h"
#include "tile.h"

class Board {
public:
  Board();
  void draw();
  void instantiate_tetromino();

private:
  int width, height;

  Tetromino *tetromino;
  Tile      **tiles;
};

#endif
