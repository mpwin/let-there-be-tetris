#include "window.h"

Window::Window()  {}
Window::~Window() {}

void Window::create()
{
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow(
        Window::title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        Window::width,
        Window::height,
        SDL_WINDOW_OPENGL
    );
    SDL_GL_CreateContext(this->window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0f, 24.0f, -2.0f, 22.0f, 0.0f, 1.0f);
}

void Window::update()
{
    SDL_GL_SwapWindow(this->window);
}

void Window::destroy()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
