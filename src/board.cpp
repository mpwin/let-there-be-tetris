#include "board.h"

Board::Board()
{
    this->width  = 10;
    this->height = 20;
    this->rows   = height;
    this->cols   = width;
    this->tiles  = new Tile*[width];

    for (int i = 0; i < width; i++)
    {
        this->tiles[i] = new Tile[height];
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            tiles[x][y].set_position(x, y);
        }
    }

    srand(time(NULL));
}

void Board::clear_full_rows()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            bool last_col  = (col + 1 == cols);
            bool tile_full = tiles[col][row].get_state() == 1;

            if (last_col && tile_full)
            {
                clear_row(row);
                row--;
            }
            else if (tile_full)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
}

void Board::clear_row(int row)
{
    for (int y = row; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            bool last_row = (y + 1 == height);

            if (last_row)
            {
                tiles[x][y].set_state(0);
            }
            else
            {
                tiles[x][y].set_state(tiles[x][y + 1].get_state());
            }
        }
    }
}

void Board::draw()
{
    glBegin(GL_QUADS);
        glColor3f(0.05f, 0.25f, 0.05f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, height);
        glVertex2f(width, height);
        glVertex2f(width, 0.0f);
    glEnd();

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            tiles[i][j].draw();
        }
    }

    tetromino->draw();
}

void Board::instantiate_tetromino()
{
    switch (rand() % 5)
    {
        case 0:
            this->tetromino = new I(width, height);
            break;
        case 1:
            this->tetromino = new L(width, height);
            break;
        case 2:
            this->tetromino = new O(width, height);
            break;
        case 3:
            this->tetromino = new T(width, height);
            break;
        case 4:
            this->tetromino = new Z(width, height);
            break;
        default:
            return;
    }
}

void Board::lock_tetromino()
{
    for (int x = 0; x < tetromino->get_width(); x++)
    {
        for (int y = 0; y < tetromino->get_height(); y++)
        {
            int tile_state = tetromino->tiles[x][y].get_state();

            if (tile_state == 1)
            {
                int tile_pos_x = tetromino->tiles[x][y].get_position_x();
                int tile_pos_y = tetromino->tiles[x][y].get_position_y();

                tiles[tile_pos_x][tile_pos_y].set_state(tile_state);
            }
        }
    }
}

void Board::process_tetromino_down()
{
    if (tetromino_can_move_down())
    {
        tetromino->move_down();
    }
    else
    {
        lock_tetromino();
        delete tetromino;
        clear_full_rows();
        instantiate_tetromino();
    }
}

void Board::process_tetromino_left()
{
    if (tetromino_can_move_left())
    {
        tetromino->move_left();
    }
}

void Board::process_tetromino_right()
{
    if (tetromino_can_move_right())
    {
        tetromino->move_right();
    }
}

void Board::process_tetromino_rotate()
{
    tetromino->rotate();
}

bool Board::tetromino_can_move_down()
{
    for (int x = 0; x < tetromino->get_width(); x++)
    {
        for (int y = 0; y < tetromino->get_height(); y++)
        {
            int tile_state = tetromino->tiles[x][y].get_state();

            if (tile_state == 1)
            {
                int  tile_pos_x = tetromino->tiles[x][y].get_position_x();
                int  tile_pos_y = tetromino->tiles[x][y].get_position_y();
                bool bottommost = tile_pos_y - 1 < 0;

                if (bottommost)
                {
                    return false;
                }
                else
                {
                    bool colliding = tiles[tile_pos_x][tile_pos_y - 1].get_state() == 1;

                    if (colliding)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Board::tetromino_can_move_left()
{
    for (int x = 0; x < tetromino->get_width(); x++)
    {
        for (int y = 0; y < tetromino->get_height(); y++)
        {
            int tile_state = tetromino->tiles[x][y].get_state();

            if (tile_state == 1)
            {
                int  tile_pos_x = tetromino->tiles[x][y].get_position_x();
                int  tile_pos_y = tetromino->tiles[x][y].get_position_y();
                bool leftmost   = tile_pos_x - 1 < 0;

                if (leftmost)
                {
                    return false;
                }
                else
                {
                    bool colliding = tiles[tile_pos_x - 1][tile_pos_y].get_state() == 1;

                    if (colliding)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Board::tetromino_can_move_right()
{
    for (int x = 0; x < tetromino->get_width(); x++)
    {
        for (int y = 0; y < tetromino->get_height(); y++)
        {
            int tile_state = tetromino->tiles[x][y].get_state();

            if (tile_state == 1)
            {
                int  tile_pos_x = tetromino->tiles[x][y].get_position_x();
                int  tile_pos_y = tetromino->tiles[x][y].get_position_y();
                bool rightmost  = tile_pos_x + 1 > width - 1;

                if (rightmost)
                {
                    return false;
                }
                else
                {
                    bool colliding = tiles[tile_pos_x + 1][tile_pos_y].get_state() == 1;

                    if (colliding)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
