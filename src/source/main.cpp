/*
  The main game loop.
  20190205
  Vishal Sood
*/

#include "game.hpp"
#include "SDL2/SDL.h"

Game *game = nullptr;

int main(int argc, char** argv)
{
  const int FramesPerSecond
    = 60;
  const int FrameDelay
    = 1000 / FramesPerSecond;
  Uint32 frameStartTime;
  int duration_frame;
  game= 
    new Game();
  game->
    init(
      "LearnToMakeGames",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      800, 600,
      false);
  while (game->is_running()) {
    frameStartTime= 
      SDL_GetTicks();
    game->
      handleEvents();
    game->
      update();
    game->
      render();
    duration_frame= 
      SDL_GetTicks() - frameStartTime;
    if (FrameDelay > duration_frame) {
      SDL_Delay(
        FrameDelay - duration_frame);
    }
  }
  game->
    clean();
  return 0;
}
