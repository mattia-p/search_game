#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <string>

class Button{

public:
    Button(const std::string& text, SDL_Rect rect, SDL_Color color, SDL_Color hoverColor);
    ~Button();

    void render(SDL_Renderer* renderer);
    bool handleEvent(SDL_Event& event);

private:

    SDL_Rect rect;
    SDL_Color color;
    SDL_Color hoverColor;
    bool isHovered;

};