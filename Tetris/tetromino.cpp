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

void Tetromino::set_tiles_shape()
{
  int *shape;

  switch (state)
  {
  case 1:
    shape = shape_1;
    break;
  case 2:
    shape = shape_2;
    break;
  case 3:
    shape = shape_3;
    break;
  case 4:
    shape = shape_4;
    break;
  default:
    return;
  }

  for (int i = 0; i < area; i++)
  {
    int row = i / width;
    int col = i % height;

    tiles[row][col].set_state(shape[i]);
  }
}