#include "tetromino.h"

void Tetromino::draw()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].draw();
    }
  }
}

void Tetromino::move_down()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].move_down();
    }
  }
}

void Tetromino::move_left()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].move_left();
    }
  }
}

void Tetromino::move_right()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].move_right();
    }
  }
}
