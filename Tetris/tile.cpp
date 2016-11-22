#include "tile.h"

Tile::Tile()
{
  state = 0;
}

void Tile::draw()
{
  if (state == 1)
  {
    glBegin(GL_QUADS);
      glColor3f(0.0f, 1.0f, 1.0f);
      glVertex2f(x, y);
      glVertex2f(x, y + 1);
      glVertex2f(x + 1, y + 1);
      glVertex2f(x + 1, y);
    glEnd();
  }
}

int Tile::get_state()
{
  return state;
}

void Tile::move_down()
{
  y--;
}

void Tile::move_left()
{
  x--;
}

void Tile::move_right()
{
  x++;
}

void Tile::set_position(int xc, int yc)
{
  x = xc;
  y = yc;
}

void Tile::set_state(int s)
{
  state = s;
}
