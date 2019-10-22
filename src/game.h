#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "window.h"

class Game
{
public:
    Game();
    ~Game();

    bool is_running() const;
    void handle_events();
    void update();
    void render();

private:
    Board  board;
    Window window;

    bool running;
    int  current_time;
    int  last_time;
};

#endif
