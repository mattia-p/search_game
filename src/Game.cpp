#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
    Astar* astar = nullptr;
}

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

    // Normal path search
    if (!is_step_search)
    {

        if (start_pose_acquired && end_pose_acquired && !a_star_done)
        {
            
            std::vector<std::vector<int>> path;

            // Astar* astar;
            astar = new Astar();

            path = astar->search(map_array, start_pose, end_pose);

            setPath(path);

            a_star_done = true;

        }

    }

    // Step by step search
    else
    {
        // If the user set the start and end position and the path search isn't over yet
        if (start_pose_acquired && end_pose_acquired && !a_star_done)
        {

            if (step_search_initialized == false)
            {
                std::cout << "Initialize astar object" << std::endl;
                astar = new Astar();
                
                step_search_initialized = true;
            }
            else
            {
                //  Do one step of the path search
                astar->StepSearch(map_array, start_pose, end_pose);

                // Update the open set and closed set objects
                setOpenSet(astar->open_set_step_search);
                setClosedSet(astar->closed_set_step_search);
            }

            // Check if the path search is over
            a_star_done = astar->search_complete;

            // If the path search if over, update the path object to plot the result
            if (a_star_done)
            {
                std::cout << "Goal found: " << std::endl;
                setPath(astar->current_path);
            }
        }
    }
}

void Game::setOpenSet(const std::vector<Node*> &open_set_nodes)
{
    open_set_step_search = {};
    for(const auto &node : open_set_nodes)
    {
        GameObject* game_obj;
        game_obj = new GameObject("../src/assets/open.png", node->x * 32, node->y * 32);
        open_set_step_search.push_back(game_obj);
    }
}

void Game::setClosedSet(const std::vector<Node*>  &closed_set_nodes)
{
    closed_set_step_search = {};
    for(const auto &node : closed_set_nodes)
    {
        GameObject* game_obj;
        game_obj = new GameObject("../src/assets/closed.png", node->x * 32, node->y * 32);
        closed_set_step_search.push_back(game_obj);
    }
}

void Game::update()
{
    //  TODO: Completely change this
    if (start_pose_acquired)
    {
        start->Update();
    }
    
    if (is_step_search)
    {
        for (auto gameobj : closed_set_step_search)
        {
            gameobj->Update();
        }

        for (auto gameobj : open_set_step_search)
        {
            gameobj->Update();
        }
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
    
    if (is_step_search)
    {
        for(auto gameobj : closed_set_step_search)
        {
            gameobj->Render(renderer);
        }

        for(auto gameobj : open_set_step_search)
        {
            gameobj->Render(renderer);
        }
    }


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
