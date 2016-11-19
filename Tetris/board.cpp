#include <cstdlib>
#include <glew.h>

#include "board.h"

Board::Board() {
  width  = 10;
  height = 20;

  tiles = new Tile*[width];
  for (int i = 0; i < width; i++) {
    tiles[i] = new Tile[height];
  }

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].set_position(i, j);
    }
  }
}

void Board::draw() {
  glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, height);
    glVertex2f(width, height);
    glVertex2f(width, 0.0f);
  glEnd();

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      tiles[i][j].draw();
    }
  }
}

void Board::instantiate_tetromino() {
  switch (rand() % 5) {
    case 0: tetromino = new I(width, height);
    case 1: tetromino = new L(width, height);
    case 2: tetromino = new O(width, height);
    case 3: tetromino = new T(width, height);
    case 4: tetromino = new Z(width, height);
    default: return;
  }
}
