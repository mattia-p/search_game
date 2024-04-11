#pragma once
// #include "Game.hpp"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

class Map
{

public:

    Map(int map_array[20][25]);
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();

private:
    SDL_Rect src, dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};