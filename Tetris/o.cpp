#include "tetromino.h"

O::O(int board_width, int board_height)
{
  size = 2;
  state = rand() % 4 + 1;

  set_shape_1();
  set_shape_2();
  set_shape_3();
  set_shape_4();

  instantiate_tiles();
  set_tiles_shape();
  set_tiles_initial_position(board_width, board_height);
}

void O::instantiate_tiles()
{
  tiles = new Tile*[size];
  for (int i = 0; i < size; i++) {
    tiles[i] = new Tile[size];
  }
}

void O::set_shape_1()
{
  int shape[] = { 1, 1,
                  1, 1 };

  shape_1 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_1[i] = shape[i];
  }
}

void O::set_shape_2()
{
  int shape[] = { 1, 1,
                  1, 1 };

  shape_2 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_2[i] = shape[i];
  }
}

void O::set_shape_3()
{
  int shape[] = { 1, 1,
                  1, 1 };

  shape_3 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_3[i] = shape[i];
  }
}

void O::set_shape_4()
{
  int shape[] = { 1, 1,
                  1, 1 };

  shape_4 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_4[i] = shape[i];
  }
}

void O::set_tiles_initial_position(int board_width, int board_height)
{
  int initial_x = (board_width / 2) - (size / 2);
  int initial_y = board_height;

  for (int i = 0; i < (size ^ 2); i++)
  {
    int row = i / size;
    int col = i % size;

    tiles[row][col].set_position(initial_x + col, initial_y - row);
  }
}

void O::set_tiles_shape()
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

  for (int i = 0; i < (size ^ 2); i++)
  {
    int row = i / size;
    int col = i % size;

    tiles[row][col].set_state(shape[i]);
  }
}
