#include <cstdlib>
#include <ctime>

#include "board.h"
#include "tetromino.h"
#include "window.h"

int main(int argc, char ** argv)
{
    Board  board;
    Window window;

    board.instantiate_tetromino();
    window.create();

    srand(time(NULL));

    int current_time, last_time = 0;

    bool running = true;
    while (running)
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
                default:
                    break;
            }
        }

        current_time = SDL_GetTicks();
        if (current_time > last_time + 750)
        {
            board.process_tetromino_down();
            last_time = current_time;
        }

        board.draw();
        window.update();
    }

    window.destroy();
    return 0;
}
