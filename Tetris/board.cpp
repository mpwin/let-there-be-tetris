#include "board.h"

Board::Board()
{
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

void Board::draw()
{
  glBegin(GL_QUADS);
    glColor3f(0.05f, 0.25f, 0.05f);
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

  tetromino->draw();
}

void Board::instantiate_tetromino()
{
  switch (rand() % 5)
  {
    case 0:
      tetromino = new I(width, height);
      break;
    case 1:
      tetromino = new L(width, height);
      break;
    case 2:
      tetromino = new O(width, height);
      break;
    case 3:
      tetromino = new T(width, height);
      break;
    case 4:
      tetromino = new Z(width, height);
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
  if (tetromino_can_move_down()) {
    tetromino->move_down();
  }
  else {
    lock_tetromino();
    delete tetromino;
    instantiate_tetromino();
  }
}

void Board::process_tetromino_left()
{
  if (tetromino_can_move_left()) {
    tetromino->move_left();
  }
}

void Board::process_tetromino_right()
{
  if (tetromino_can_move_right()) {
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
        int tile_pos_x = tetromino->tiles[x][y].get_position_x();
        int tile_pos_y = tetromino->tiles[x][y].get_position_y();

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
        int tile_pos_x = tetromino->tiles[x][y].get_position_x();
        int tile_pos_y = tetromino->tiles[x][y].get_position_y();

        bool leftmost = tile_pos_x - 1 < 0;
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
        int tile_pos_x = tetromino->tiles[x][y].get_position_x();
        int tile_pos_y = tetromino->tiles[x][y].get_position_y();

        bool rightmost = tile_pos_x + 1 > width - 1;
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
