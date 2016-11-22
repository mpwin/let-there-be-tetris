#ifndef TETROMINO_H
#define TETROMINO_H

#include <cstdlib>
#include <ctime>

#include "tile.h"

class Tetromino
{
public:
  void draw();
  int  get_height();
  int  get_width();
  void instantiate_tiles();
  void move_down();
  void move_left();
  void move_right();
  void rotate();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();

protected:
  int width, height, area;
  int state;
  int *shape_1, *shape_2, *shape_3, *shape_4;

  Tile **tiles;
};

class I : public Tetromino
{
public:
  I(int board_width, int board_height);

private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

class L : public Tetromino
{
public:
  L(int board_width, int board_height);

private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

class O : public Tetromino
{
public:
  O(int board_width, int board_height);

private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

class T : public Tetromino
{
public:
  T(int board_width, int board_height);

private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

class Z : public Tetromino
{
public:
  Z(int board_width, int board_height);

private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

#endif
