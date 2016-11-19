#include "tetromino.h"

void Tetromino::draw()
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      tiles[i][j].draw();
    }
  }
}
