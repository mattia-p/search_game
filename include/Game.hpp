#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Map.hpp"
#include "GameObject.hpp"
#include <vector>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    void loadMap(int arr[20][25]);
    void setStart(int x, int y);
    void setEnd(int x, int y);
    void setPath(std::vector<std::vector<int>> path_coordinates);

    bool running() {return isRunning;}

    static SDL_Renderer *renderer;

    Map* map;
    GameObject* start;
    GameObject* end;
    std::vector<GameObject*> path;

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    
};

#endif 