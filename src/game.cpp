#include "game.h"

Game::Game()
{
    board.instantiate_tetromino();
    window.create();

    running      = true;
    current_time = 0;
    last_time    = 0;
}

Game::~Game()
{
    window.destroy();
}

void Game::handle_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        board.process_tetromino_down();
                        break;
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_LEFT:
                        board.process_tetromino_left();
                        break;
                    case SDLK_RIGHT:
                        board.process_tetromino_right();
                        break;
                    case SDLK_UP:
                        board.process_tetromino_rotate();
                        break;
                    default:
                        break;
                }
                break;
            }
            default: break;
        }
    }
}

void Game::update()
{
    current_time = SDL_GetTicks();

    if (current_time > last_time + 750)
    {
        board.process_tetromino_down();
        last_time = current_time;
    }
}

void Game::render()
{
    board.draw();
    window.update();
}

bool Game::is_running() const
{
    return running;
}
