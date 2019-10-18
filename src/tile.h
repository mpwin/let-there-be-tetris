#ifndef TILE_H
#define TILE_H

#include <GL/glew.h>

class Tile
{
public:
    Tile();
    void draw();
    int  get_position_x();
    int  get_position_y();
    int  get_state();
    void move_down();
    void move_left();
    void move_right();
    void set_position(int x, int y);
    void set_state(int state);

private:
    int x, y;
    int state;
};

#endif
