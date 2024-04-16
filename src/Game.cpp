#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

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

}

void Game::loadMap(int arr[20][25])
{
    map = new Map(arr);

    // TODO: Make this better, or use std::copy
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 25; ++j) {
            map_array[i][j] = arr[i][j];
        }
    }
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
        GameObject* game_obj;
        game_obj = new GameObject("../src/assets/path.png", point[0] * 32, point[1] * 32);
        path.push_back(game_obj);
    }
}

void Game::handleEvents()
{
    // std::cout << "Handle events" << std::endl;
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (start_pose_acquired == false)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                start_pose_acquired = true;

                setStart(mouseX / 32, mouseY / 32);
                // start_pose = {mouseX / 32, mouseY / 32};
                start_pose[0] = mouseX / 32;
                start_pose[1] = mouseY / 32;
            }
            else if (start_pose_acquired == true && end_pose_acquired == false)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                
                end_pose_acquired = true;

                setEnd(mouseX / 32, mouseY / 32);

                end_pose[0] = mouseX / 32;
                end_pose[1] = mouseY / 32;

            }
            
        }
    }


    if (start_pose_acquired && end_pose_acquired && !a_star_done)
    {
        std::cout << "Search for solution" << std::endl;
        
        std::vector<std::vector<int>> path;

        Astar* astar;
        astar = new Astar();

        path = astar->search(map_array, start_pose, end_pose);

        // std::cout << "Path found: " << std::endl;
        // for (auto point : path)
        // {
        //     std::cout << point[0] << ", " << point[1] << std::endl;
        // }

        setPath(path);

        a_star_done = true;
        
    }
}

void Game::update()
{
    //  TODO: Completely change this
    if (start_pose_acquired)
    {
        start->Update();
    }
    
    if (a_star_done)
    {
        for (auto gameobj : path)
        {
            gameobj->Update();
        }
    }

    if (end_pose_acquired)
    {
        end->Update();
    }
}

void Game::render()
{
    // Clear renderer buffer
    SDL_RenderClear(renderer);

    // Add stuff to render here
    map->DrawMap();

    if (start_pose_acquired)
    {
        start->Render(renderer);
    }

    if (a_star_done)
    {
        for (auto gameobj : path)
        {
            gameobj->Render(renderer);
        }
    }
    
    if (end_pose_acquired)
    {
        end->Render(renderer);
    }

    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
