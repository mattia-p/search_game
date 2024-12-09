#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

#include <memory> // for smart pointer
#include <cstring>  // For std::memcpy

#include <chrono>

SDL_Renderer* Game::renderer = nullptr;

Game::Game(){
}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, bool is_step_search_in)
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

    is_step_search = is_step_search_in;

}

void Game::loadMap(int arr[20][25])
{
    // Create Map object (just for visualization)
    map = std::make_unique<Map>(arr);

    // Directly assign the contents of arr to map_array
    std::memcpy(map_array, arr, sizeof(map_array));

}

void Game::setStart(int x, int y)
{
    // Create GameObject and push it to GameObjects vector
    GameObjects.push_back(std::make_unique<GameObject>("../src/assets/start.png", x*32, y*32));
}

void Game::setEnd(int x, int y)
{   
    // Create GameObject and push it to GameObjects vector
    GameObjects.push_back(std::make_unique<GameObject>("../src/assets/end.png", x*32, y*32));
}

void Game::setPath(std::vector<std::vector<int>> path_coordinates)
{
    for(auto point : path_coordinates)
    {
        // Create GameObject and push it to GameObjects vector
        GameObjects.push_back(std::make_unique<GameObject>("../src/assets/path.png", point[0] * 32, point[1] * 32));
    }
}

void Game::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)){

        switch (event.type){

            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT){
                    
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);

                    if (!start_pose_acquired){
                        
                        start_pose_acquired = true;

                        setStart(mouseX / 32, mouseY / 32);
                        // start_pose = {mouseX / 32, mouseY / 32};
                        start_pose[0] = mouseX / 32;
                        start_pose[1] = mouseY / 32;
                    }
                    else if (start_pose_acquired && !end_pose_acquired)
                    {
                        
                        end_pose_acquired = true;

                        setEnd(mouseX / 32, mouseY / 32);

                        end_pose[0] = mouseX / 32;
                        end_pose[1] = mouseY / 32;

                    }
                    
                }
        }
    }
}

void Game::handleSearch()
{

    if(!is_step_search){


        if (start_pose_acquired && end_pose_acquired && !a_star_done){
                
            std::cout << "Start astar search" << std::endl;

            std::vector<std::vector<int>> path;

            // Create local instance of astar class
            Astar astar;

            auto start = std::chrono::high_resolution_clock::now();

            path = astar.search(map_array, start_pose, end_pose);

            auto end = std::chrono::high_resolution_clock::now();

            // Calculate the duration in microseconds
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            // Output the duration in microseconds
            std::cout << "Elapsed time: " << duration.count() << " microseconds." << std::endl;
            
            // TODO: Make sure is returns something before we call setPath
            setPath(path);

            a_star_done = true;
        }
    }

    // else{

    //     // Step by step search
    //     if (start_pose_acquired && end_pose_acquired && !a_star_done){

    //         if (step_search_initialized == false){
    //             std::cout << "Initialize astar object" << std::endl;
                
    //             // Initialize astar with smart pointer
    //             astar = std::make_unique<Astar>();
                
    //             step_search_initialized = true;
    //         }
    //         else{
    //             //  Do one step of the path search
    //             astar->StepSearch(map_array, start_pose, end_pose);

    //             // Update the open set and closed set objects
    //             setOpenSet(astar->open_set_step_search);
    //             setClosedSet(astar->closed_set_step_search);
    //         }

    //         // Check if the path search is over
    //         // TODO: ERROR? This creates a local variable a_star_done rather than modifying the class member. 
    //         // bool a_star_done = astar->search_complete;

    //         // If the path search if over, update the path object to plot the result
    //         if (astar->search_complete)
    //         {
    //             // std::cout << "Goal found: " << std::endl;
    //             setPath(astar->current_path);
    //             a_star_done = true;
    //         }

    //     }

    // }
}

void Game::setOpenSet(const std::vector<std::unique_ptr<Node>> &open_set_nodes){
    
    // Clear the previous content
    open_set_step_search.clear();

    for(const auto &node : open_set_nodes){

        auto game_obj = std::make_unique<GameObject>("../src/assets/open.png", node->x * 32, node->y * 32);
        // Move ownership into the vector
        open_set_step_search.push_back(std::move(game_obj));
    }
}

void Game::setClosedSet(const std::vector<std::unique_ptr<Node>>  &closed_set_nodes){
    
    // Clear the previous content
    closed_set_step_search.clear();

    for(const auto &node : closed_set_nodes){

        auto game_obj = std::make_unique<GameObject>("../src/assets/closed.png", node->x * 32, node->y * 32);
        // Move ownership into the vector
        closed_set_step_search.push_back(std::move(game_obj));
    }
}

void Game::update()
{

    if (is_step_search)
    {
        for (auto& gameobj : closed_set_step_search)
        {
            gameobj->Update();
        }

        for (auto& gameobj : open_set_step_search)
        {
            gameobj->Update();
        }
    }

  
    // Update the start, end and path objects
    for (const auto& gameobj : GameObjects)
    {
        gameobj->Update();
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
        for(auto& gameobj : closed_set_step_search)
        {
            gameobj->Render(renderer);
        }

        for(auto& gameobj : open_set_step_search)
        {
            gameobj->Render(renderer);
        }
    }

    // Render the start, end and path objects
    for(const auto& gameobj: GameObjects){
        gameobj->Render(renderer);
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
