#include <stdlib.h>

#include <glew.h>

#include "tile.h"

Tile::Tile() {
  state = rand() % 2;
}

void Tile::draw() {
  if (state == 1) {
    glBegin(GL_QUADS);
      glColor3f(0.0f, 1.0f, 1.0f);
      glVertex2f(x, y);
      glVertex2f(x, y + 1);
      glVertex2f(x + 1, y + 1);
      glVertex2f(x + 1, y);
    glEnd();
  }
}

void Tile::set_position(int xc, int yc) {
  x = xc;
  y = yc;
}
