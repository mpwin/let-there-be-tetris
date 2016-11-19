#ifndef TETROMINO_H
#define TETROMINO_H

#include "tile.h"

class Tetromino
{
protected:
  int size;
  int state;
  int *shape_1, *shape_2, *shape_3, *shape_4;
  Tile **tiles;
};

class I : public Tetromino
{
public:
  I(int board_width, int board_height);
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();
};

class L : public Tetromino
{
public:
  L(int board_width, int board_height);
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();
};

class O : public Tetromino
{
public:
  O(int board_width, int board_height);
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();
};

class T : public Tetromino
{
public:
  T(int board_width, int board_height);
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();
};

class Z : public Tetromino
{
public:
  Z(int board_width, int board_height);
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_initial_position(int board_width, int board_height);
  void set_tiles_shape();
};

#endif
