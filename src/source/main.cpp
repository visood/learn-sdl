/*
  The main game loop.
  20190205
  Vishal Sood
*/

#include "game.hpp"

Game *game = nullptr;

int main(int argc, char** argv) {
  game=
    new Game();
  game->init(
    "LearnToMakeGames",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800, 600,
    false);
  while (game->is_running()) {
    game->handleEvents();
    game->update();
    game->render(); }
  game->clean();
    
  return 0;
}
