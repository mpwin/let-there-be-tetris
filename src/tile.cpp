#include "tile.h"

Tile::Tile()
{
    state = 0;
}

void Tile::draw()
{
    if (state == 1)
    {
        float border_width = 0.05f;

        glBegin(GL_QUADS);
            glColor3f(0.00f, 0.00f, 0.00f);
            glVertex2f(x, y);
            glVertex2f(x, y + 1);
            glVertex2f(x + 1, y + 1);
            glVertex2f(x + 1, y);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.02f, 0.60f, 0.02f);
            glVertex2f(x + border_width, y + border_width);
            glVertex2f(x + border_width, y + 1 - border_width);
            glVertex2f(x + 1 - border_width, y + 1 - border_width);
            glVertex2f(x + 1 - border_width, y + border_width);
        glEnd();
    }
}

int Tile::get_position_x()
{
    return x;
}

int Tile::get_position_y()
{
    return y;
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

void Tile::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Tile::set_state(int s)
{
    state = s;
}
