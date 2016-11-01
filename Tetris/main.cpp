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
