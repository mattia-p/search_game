#include "Button.hpp"
#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <string>

Button::Button(const std::string& text, SDL_Rect rect, SDL_Color color, SDL_Color hoverColor):
    rect(rect), color(color), hoverColor(hoverColor), isHovered(false){

}

Button::~Button(){

}


void Button::render(SDL_Renderer* renderer){
    
    // Change color if hovered
    SDL_SetRenderDrawColor(renderer, isHovered ? hoverColor.r : color.r,
                            isHovered ? hoverColor.g : color.g,
                            isHovered ? hoverColor.b : color.b,
                            255);

    SDL_RenderFillRect(renderer, &rect);
}

bool Button::handleEvent(SDL_Event& event){

    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;

            // Check if the mouse is over the button
            isHovered = (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
                         mouseY >= rect.y && mouseY <= rect.y + rect.h);

            if (event.type == SDL_MOUSEBUTTONDOWN && isHovered) {
                // Button was clicked
                return true;
            }
        }
        return false;

}