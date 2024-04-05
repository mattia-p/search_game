#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
GameObject* player2;
Map* map;

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

    player = new GameObject("../src/assets/player.png", 0, 0);
    player2 = new GameObject("../src/assets/grass.png", 50, 50);
    map = new Map();

    // playerTex = TextureManager::LoadTexture("../src/assets/player.png", renderer);
    // SDL_Surface* tmpSurface = IMG_Load("../src/assets/player.png");
    // if(!tmpSurface)
    // {
    //     std::cout << "Error loading image: " << IMG_GetError() << std::endl;
    // }
    // playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    // SDL_FreeSurface(tmpSurface);
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
    player->Update();
    player2->Update();
}

void Game::render()
{
    // Clear renderer buffer
    SDL_RenderClear(renderer);

    // Add stuff to render here
    // SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    map->DrawMap();
    player->Render();
    player2->Render();

    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
