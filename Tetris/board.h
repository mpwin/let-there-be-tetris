#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <glew.h>

#include "tetromino.h"
#include "tile.h"

class Board
{
public:
  Board();
  void draw();
  void instantiate_tetromino();
  void move_tetromino_down();
  void move_tetromino_left();
  void move_tetromino_right();

private:
  int width, height;

  Tetromino *tetromino;
  Tile      **tiles;
};

#endif
