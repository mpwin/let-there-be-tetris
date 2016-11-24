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
  void clear_full_rows();
  void clear_row(int row);
  void draw();
  void instantiate_tetromino();
  void lock_tetromino();
  void process_tetromino_down();
  void process_tetromino_left();
  void process_tetromino_right();
  void process_tetromino_rotate();
  bool tetromino_can_move_down();
  bool tetromino_can_move_left();
  bool tetromino_can_move_right();

private:
  int width, height;
  int rows, cols;

  Tetromino *tetromino;
  Tile      **tiles;
};

#endif
