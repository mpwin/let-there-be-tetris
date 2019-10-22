#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SDL.h>

class Window
{
public:
    Window();
    ~Window();

    void create();
    void update();
    void destroy();

private:
    SDL_Window *window;

    static constexpr const char *title = "Let There Be Tetris";
    static const int width  = 1024;
    static const int height = 768;
};

#endif
