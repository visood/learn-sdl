/*
  Game class
  20190205
  Vishal Sood
*/

#include <iostream>
#include "SDL2/SDL.h"
#include <exception>

class Game {
public:
  Game();
  ~Game();

  void init(
    const char* title,
    int xpos,
    int ypos,
    int width,
    int height,
    bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool is_running(){ return _is_running;}

private:
  uint32_t _update_count;
  bool _is_running         = false;;
  SDL_Window* _window      = nullptr;
  SDL_Renderer* _renderer  = nullptr;
};
