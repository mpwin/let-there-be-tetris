#ifndef TETROMINO_H
#define TETROMINO_H

#include "tile.h"

class Tetromino {
protected:
  int size;
  int state;
  int *shape_1, *shape_2, *shape_3, *shape_4;
  Tile **tiles;
};

class I : public Tetromino {
public:
  I();
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_shape();
};

class L : public Tetromino {
public:
  L();
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_shape();
};

class O : public Tetromino {
public:
  O();
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_shape();
};

class T : public Tetromino {
public:
  T();
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_shape();
};

class Z : public Tetromino {
public:
  Z();
private:
  void instantiate_tiles();
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
  void set_tiles_shape();
};

#endif
