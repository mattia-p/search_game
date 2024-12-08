#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Map.hpp"
#include "GameObject.hpp"
#include <vector>
#include "astar.hpp"
#include "Node.hpp"


class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void handleSearch();
    void update();
    void render();
    void clean();

    void loadMap(int arr[20][25]);
    void setStart(int x, int y);
    void setEnd(int x, int y);
    void setPath(std::vector<std::vector<int>> path_coordinates);

    bool running() {return isRunning;}
    bool isRunning;

    static SDL_Renderer *renderer;

    Map* map;
    int map_array[20][25];
    GameObject* start;
    GameObject* end;
    std::vector<GameObject*> path;

    // Step search
    Astar* astar;
    bool is_step_search = false;
    bool step_search_initialized = false;
    std::vector<GameObject*> open_set_step_search;
    std::vector<GameObject*> closed_set_step_search;
    void setOpenSet(const std::vector<Node*>  &open_set_nodes);
    void setClosedSet(const std::vector<Node*> &closed_set_nodes);

    int start_pose[2];
    int end_pose[2];
    bool start_pose_acquired = false;
    bool end_pose_acquired = false;
    bool a_star_done = false;

private:
    int cnt = 0;
    SDL_Window *window;
    
};

#endif 