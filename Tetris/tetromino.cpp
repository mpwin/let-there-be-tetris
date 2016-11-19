#include "tetromino.h"

void Tetromino::draw()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].draw();
    }
  }
}
