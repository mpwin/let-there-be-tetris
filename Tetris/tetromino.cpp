#include "tetromino.h"

void Tetromino::draw()
{
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      tiles[x][y].draw();
    }
  }
}

int Tetromino::get_height()
{
  return height;
}

int Tetromino::get_width()
{
  return width;
}

void Tetromino::instantiate_tiles()
{
  this->tiles = new Tile*[width];
  for (int i = 0; i < width; i++) {
    this->tiles[i] = new Tile[height];
  }
}

void Tetromino::move_down()
{
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      tiles[x][y].move_down();
    }
  }
}

void Tetromino::move_left()
{
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      tiles[x][y].move_left();
    }
  }
}

void Tetromino::move_right()
{
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      tiles[x][y].move_right();
    }
  }
}

void Tetromino::rotate()
{
  if (state == 4)
    this->state = 1;
  else
    this->state++;

  set_tiles_shape();
}

void Tetromino::set_tiles_initial_position(int board_width, int board_height)
{
  int initial_x = (board_width / 2) - (width / 2);
  int initial_y = board_height - 1;

  for (int i = 0; i < area; i++)
  {
    int row = i / width;
    int col = i % height;

    tiles[row][col].set_position(initial_x + col, initial_y - row);
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
