#include "Game.hpp"
#include <vector>
#include "astar.hpp"

Game *game = nullptr;


int lvl1[20][25] = {
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int main(int argc, const char * argv[])
{
    std::cout << "in main" << std::endl;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game;

    game->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    game->loadMap(lvl1);

    game->setStart(1, 10);
    game->setEnd(2, 2);
    
    // Result path {{x1, y1}, {x2, y2} ...}
    std::vector<std::vector<int>> path;
    // game->start[0] = 1;
    // game->start[1] = 2;

    // game->end[0] = 10;
    // game->end[1] = 12;

    // std::cout << "Start: " << game->start[0] << ", " << game->start[1] << std::endl;
    // std::cout << "End: " << game->end[0] << ", " << game->end[1] << std::endl;

    // Game->load_map()
    // Start position = 
  
    // find path
    int start_pose[2] = {1, 10};
    int end_pose[2] = {2, 2};
    Astar* astar;
    astar = new Astar(2);

    std::cout << "Start: " << start_pose[1] << ", " << start_pose[1] << std::endl;
    std::cout << "Goal: " << end_pose[1] << ", " << end_pose[1] << std::endl;

    path = astar->search(lvl1, start_pose, end_pose);

    std::cout << "Path: " << std::endl;
    for (auto point : path)
    {
        std::cout << point[0] << ", " << point[1] << std::endl;
    }

    game->setPath(path);

    // Plot path

    while(game->running())
    {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        // Limit frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}