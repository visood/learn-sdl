#include "game.hpp"
#include "SDL2/SDL.h"

Game::Game()
{}
Game::~Game()
{}
void Game::init(
  const char* title,
  int xpos,
  int ypos,
  int width,
  int height,
  bool fullscreen)
{ _update_count= 0;
  uint32_t flags=
    fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
  const auto initialization=
    SDL_Init(SDL_INIT_EVERYTHING);
  if (initialization != 0) {
    std::cout << "FAILURE: initialization failed with code "
              << initialization
              << std::endl;
    throw  "SDL initialization failed."; }
      
  else
    std::cout << "SUCCESS: SDL subsystems initialized"
              << std::endl;
  _window=
    SDL_CreateWindow(
      title,
      xpos, ypos,
      width, height,
      flags);
  if (not _window)
    throw 
      "FAILURE: could not create a window.";
  _renderer=
    SDL_CreateRenderer(_window, -1, 0);
  if (not _renderer)
    throw 
      "FAILURE: could not create a renderer.";
  SDL_SetRenderDrawColor(
    _renderer,
    255, 255, 255, 255);
  _is_running = true; }

void Game::handleEvents()
{ SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT: _is_running = false; break;
  default: break; } }
  
void Game::update()
{ _update_count++;
  std::cout << "Example showing that update is called in the game loop."
            << std::endl
            << "Game update count " << _update_count
            << std::endl;}
void Game::render()
{ SDL_RenderClear(_renderer);
  //add stuff to render here
  SDL_RenderPresent(_renderer);}
void Game::clean()
{ SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
  std::cout << "Game cleaned;"
            << std::endl;}

