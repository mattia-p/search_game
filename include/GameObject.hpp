#pragma once
// #include "Game.hpp"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

class GameObject {

public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();

    void Update();
    void Render(SDL_Renderer* ren);

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

};