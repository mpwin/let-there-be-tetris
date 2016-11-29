#include "tetromino.h"

I::I(int board_width, int board_height)
{
  this->width  = 4;
  this->height = 4;
  this->area   = width * height;

  this->state = rand() % 4 + 1;

  set_shape_1();
  set_shape_2();
  set_shape_3();
  set_shape_4();

  instantiate_tiles();
  set_tiles_shape();
  set_tiles_initial_position(board_width, board_height);
}

void I::set_shape_1()
{
  int shape[] = { 0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0,
                  0, 1, 0, 0 };

  this->shape_1 = new int[area];
  for (int i = 0; i < area; i++) {
    this->shape_1[i] = shape[i];
  }
}

void I::set_shape_2()
{
  int shape[] = { 0, 0, 0, 0,
                  1, 1, 1, 1,
                  0, 0, 0, 0,
                  0, 0, 0, 0 };

  this->shape_2 = new int[area];
  for (int i = 0; i < area; i++) {
    this->shape_2[i] = shape[i];
  }
}

void I::set_shape_3()
{
  int shape[] = { 0, 0, 1, 0,
                  0, 0, 1, 0,
                  0, 0, 1, 0,
                  0, 0, 1, 0 };

  this->shape_3 = new int[area];
  for (int i = 0; i < area; i++) {
    this->shape_3[i] = shape[i];
  }
}

void I::set_shape_4()
{
  int shape[] = { 0, 0, 0, 0,
                  0, 0, 0, 0,
                  1, 1, 1, 1,
                  0, 0, 0, 0 };

  this->shape_4 = new int[area];
  for (int i = 0; i < area; i++) {
    this->shape_4[i] = shape[i];
  }
}
