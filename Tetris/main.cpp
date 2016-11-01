#include <glew.h>
#include <SDL.h>

int main(int argc, char ** argv)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow(
    "Tetris",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    1024,
    768,
    SDL_WINDOW_OPENGL
  );
  SDL_Surface *screen = SDL_GetWindowSurface(window);

  SDL_GL_CreateContext(window);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);

  bool running = true; 
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              running = false;
              break;
          }
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
