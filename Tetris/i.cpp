#include "tetromino.h"

I::I(int board_width, int board_height)
{
  width  = 4;
  height = 4;
  area   = width * height;

  state = rand() % 4 + 1;

  set_shape_1();
  set_shape_2();
  set_shape_3();
  set_shape_4();

  instantiate_tiles();
  set_tiles_shape();
  set_tiles_initial_position(board_width, board_height);
}

void I::instantiate_tiles()
{
  tiles = new Tile*[width];
  for (int i = 0; i < width; i++) {
    tiles[i] = new Tile[height];
  }
}

void I::set_shape_1()
{
  int shape[] = { 0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0 };

  shape_1 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_1[i] = shape[i];
  }
}

void I::set_shape_2()
{
  int shape[] = { 0, 0, 0, 0,
                  1, 1, 1, 1,
                  0, 0, 0, 0,
                  0, 0, 0, 0 };

  shape_2 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_2[i] = shape[i];
  }
}

void I::set_shape_3()
{
  int shape[] = { 0, 0, 1, 0,
                  0, 0, 1, 0,
                  0, 0, 1, 0,
                  0, 0, 1, 0 };

  shape_3 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_3[i] = shape[i];
  }
}

void I::set_shape_4()
{
  int shape[] = { 0, 0, 0, 0,
                  0, 0, 0, 0,
                  1, 1, 1, 1,
                  0, 0, 0, 0 };

  shape_4 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_4[i] = shape[i];
  }
}

void I::set_tiles_initial_position(int board_width, int board_height)
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

void I::set_tiles_shape()
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
