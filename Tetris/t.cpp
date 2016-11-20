#include "tetromino.h"

T::T(int board_width, int board_height)
{
  width  = 3;
  height = 3;
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

void T::instantiate_tiles()
{
  tiles = new Tile*[width];
  for (int i = 0; i < width; i++) {
    tiles[i] = new Tile[height];
  }
}

void T::set_shape_1()
{
  int shape[] = { 0, 0, 0,
                  0, 1, 0,
                  1, 1, 1 };

  shape_1 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_1[i] = shape[i];
  }
}

void T::set_shape_2()
{
  int shape[] = { 1, 0, 0,
                  1, 1, 0,
                  1, 0, 0 };

  shape_2 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_2[i] = shape[i];
  }
}

void T::set_shape_3()
{
  int shape[] = { 1, 1, 1,
                  0, 1, 0,
                  0, 0, 0 };

  shape_3 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_3[i] = shape[i];
  }
}

void T::set_shape_4()
{
  int shape[] = { 0, 0, 1,
                  0, 1, 1,
                  0, 0, 1 };

  shape_4 = new int[area];
  for (int i = 0; i < area; i++) {
    shape_4[i] = shape[i];
  }
}
