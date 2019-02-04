/*
  Present a list of all the tutorials available.
  2019024
  Vishal Sood
*/

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
  std::cout << "Hello!" << std::endl;
  std::cout << (argc > 1 ? argv[1] : "")
            << std::endl
            << "initialize SDL? "
            << (SDL_Init(SDL_INIT_VIDEO) == 0 ? "SUCCESS" : "FAILURE")
            << "; " << std::endl;
  return 0;
}
