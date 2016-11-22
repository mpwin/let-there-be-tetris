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
  for (int row = 0; row < tetromino->get_width(); row++)
  {
    for (int col = 0; col < tetromino->get_height(); col++)
    {
      int tetromino_tile_state = tetromino->tiles[row][col].get_state();
      if (tetromino_tile_state == 1)
      {
        int tetromino_tile_position_x = tetromino->tiles[row][col].get_position_x();
        int tetromino_tile_position_y = tetromino->tiles[row][col].get_position_y();

        tiles[tetromino_tile_position_x][tetromino_tile_position_y].set_state(tetromino_tile_state);
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
  for (int row = 0; row < tetromino->get_width(); row++)
  {
    for (int col = 0; col < tetromino->get_height(); col++)
    {
      int tetromino_tile_state = tetromino->tiles[row][col].get_state();
      if (tetromino_tile_state == 1)
      {
        int tetromino_tile_position_y = tetromino->tiles[row][col].get_position_y();
        if (tetromino_tile_position_y - 1 < 0)
        {
          return false;
        }
      }
    }
  }

  return true;
}

bool Board::tetromino_can_move_left()
{
  for (int row = 0; row < tetromino->get_width(); row++)
  {
    for (int col = 0; col < tetromino->get_height(); col++)
    {
      int tetromino_tile_state = tetromino->tiles[row][col].get_state();
      if (tetromino_tile_state == 1)
      {
        int tetromino_tile_position_x = tetromino->tiles[row][col].get_position_x();
        if (tetromino_tile_position_x - 1 < 0)
        {
          return false;
        }
      }
    }
  }

  return true;
}

bool Board::tetromino_can_move_right()
{
  for (int row = 0; row < tetromino->get_width(); row++)
  {
    for (int col = 0; col < tetromino->get_height(); col++)
    {
      int tetromino_tile_state = tetromino->tiles[row][col].get_state();
      if (tetromino_tile_state == 1)
      {
        int tetromino_tile_position_x = tetromino->tiles[row][col].get_position_x();
        if (tetromino_tile_position_x + 1 > width - 1)
        {
          return false;
        }
      }
    }
  }

  return true;
}
