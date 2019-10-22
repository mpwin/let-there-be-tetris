#include "game.h"

int main(int argc, char **argv)
{
    Game *game = new Game();

    while (game->is_running())
    {
        game->handle_events();
        game->update();
        game->render();
    }

    return 0;
}
