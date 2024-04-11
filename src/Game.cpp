#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

// int lvl1[20][25] = {
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// };

// GameObject* start;
// GameObject* player;
// Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem initialized ..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }

        isRunning = true;
    }
    else{
        isRunning = false;
    }

    // player = new GameObject("../src/assets/dirt.png", 0, 0);
    // start = new GameObject("../src/assets/dirt.png", 20, 30);
    // player2 = new GameObject("../src/assets/grass.png", 50, 50);
    // map = new Map(lvl1);
    // map = new Map(lvl1);

    // playerTex = TextureManager::LoadTexture("../src/assets/player.png", renderer);
    // SDL_Surface* tmpSurface = IMG_Load("../src/assets/player.png");
    // if(!tmpSurface)
    // {
    //     std::cout << "Error loading image: " << IMG_GetError() << std::endl;
    // }
    // playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    // SDL_FreeSurface(tmpSurface);
}

void Game::loadMap(int arr[20][25])
{
    map = new Map(arr);
}

void Game::setStart(int x, int y)
{
    start = new GameObject("../src/assets/start.png", x*32, y*32);
}

void Game::setEnd(int x, int y)
{
    end = new GameObject("../src/assets/end.png", x*32, y*32);
}

void Game::setPath(std::vector<std::vector<int>> path_coordinates)
{
    for(auto point : path_coordinates)
    {
        // std::cout << point[0] << std::endl;
        GameObject* game_obj;
        game_obj = new GameObject("../src/assets/path.png", point[0] * 32, point[1] * 32);
        path.push_back(game_obj);
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    // player->Update();
    start->Update();
    end->Update();

    // player2->Update();

    for (auto gameobj : path)
    {
        gameobj->Update();
    }
}

void Game::render()
{
    // Clear renderer buffer
    SDL_RenderClear(renderer);

    // Add stuff to render here
    // SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    map->DrawMap();
    // draw start 
    // draw end
    // draw path
    // player->Render(renderer);


    start->Render(renderer);
    

    for (auto gameobj : path)
    {
        gameobj->Render(renderer);
    }

    end->Render(renderer);



    // player2->Render();

    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
