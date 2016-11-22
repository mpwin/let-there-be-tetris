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
  void process_tetromino_down();
  void process_tetromino_left();
  void process_tetromino_right();
  void process_tetromino_rotate();

private:
  int width, height;

  Tetromino *tetromino;
  Tile      **tiles;
};

#endif
