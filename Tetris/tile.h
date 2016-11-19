#ifndef TILE_H
#define TILE_H

#include <cstdlib>
#include <glew.h>

class Tile
{
public:
  Tile();
  void draw();
  void set_position(int x, int y);
  void set_state(int state);

private:
  int x, y;
  int state;
};

#endif
