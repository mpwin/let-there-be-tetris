#include <glew.h>

#include "board.h"

Board::Board() {
  width  = 10;
  height = 20;
}

void Board::draw() {
  glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
  glEnd();
}
