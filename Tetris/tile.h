#ifndef TILE_H
#define TILE_H

class Tile {
public:
  Tile();
  void draw();
  void set_position(int x, int y);

private:
  int x, y;
  int state;
};

#endif
