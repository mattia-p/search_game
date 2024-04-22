#include "astar.hpp"

Astar::Astar(){}

Astar::~Astar(){}

bool Astar::Compare(const Node* node1, const Node* node2)
{
    float f1 = node1->g + node1->h;
    float f2 = node2->g + node2->h;
    return f1 > f2; 
}

void Astar::sortSet(std::vector<Node*> &set)
{
    std::sort(set.begin(), set.end(), Compare);
}

void Astar::ExpandNeighbors(Node* &current_node, int map[20][25], std::vector<Node*> &open_set, std::vector<Node*> &closed_set, int end[2])
{
    // directions
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // Loop through current node's potential neighbors
    for (int i = 0; i < 4; i++)
    {
        int x2 = current_node->x + delta[i][0];
        int y2 = current_node->y + delta[i][1];

        // Check that the potential neighbor is valid (in map and not in obstacle)
        if (CheckValidNode(x2, y2, map))
        {

            // If node is already in the closed set, don't do anything
            bool node_already_in_closed_set = NodeInClosedSet(x2, y2, closed_set);
            if (node_already_in_closed_set == false)
            {

                // Check if Node is already in open set
                Node* neighbor_node = GetNodeFromOpenSet(x2, y2, open_set);

                // If it's already in the open set
                if (neighbor_node != nullptr)
                {
                    int tentative_g = current_node->g + 1;
                    
                    // If it's new g cost is smaller than it's existing one 
                    if (tentative_g < neighbor_node->g)
                    {
                        // Set its parent as the current node
                        neighbor_node->g = tentative_g;
                        // neighbor_node->h = tentative_g;
                        neighbor_node->parent = current_node; // Not sure about that
                    }
                }
                else
                {
                    float new_g = current_node->g + 1;
                    float new_h = Node::heurestic(x2, y2, end[0], end[1]);
                    Node* new_node = new Node(x2, y2, new_g, new_h);
                    new_node->parent = current_node;
                    open_set.push_back(new_node);
                }

            }

        }
    }
}

bool Astar::NodeInClosedSet(int x, int y, std::vector<Node*> &closed_set)
{
    for(auto node: closed_set)
    {
        if((node->x == x) && (node->y == y))
        {
            return true;
        }
    }

    return false;
}

Node* Astar::GetNodeFromOpenSet(int x, int y, std::vector<Node*> &open_set)
{
    for(auto node : open_set)
    {
        if((node->x == x) && (node->y == y))
        {
            return node;
        }
    }
    return nullptr;
}

bool Astar::CheckValidNode(int x, int y, int map[20][25])
{
    bool on_grid_x = (x >= 0 && x < 25);
    bool on_grid_y = (y >= 0 && y < 20);

    bool is_obstacle = (map[y][x] == 0);
    

    if (on_grid_x && on_grid_y && !is_obstacle)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<std::vector<int>> Astar::SearchBack(Node* &current_node)
{
    std::vector<std::vector<int>> output_path = {};
    
    while (current_node->parent != nullptr)
    {

        output_path.push_back({current_node->x, current_node->y});
        current_node = current_node->parent;
    }

    return output_path;
}

std::vector<std::vector<int>> Astar::search(int map[20][25], int start[2], int end[2])
{

    std::vector<std::vector<int>> output{};

    // Node that were already visited
    std::vector<Node*> closed_set;

    std::vector<Node*> open_set;
    float h = Node::heurestic(start[0], start[1], end[0], end[1]);

    Node start_node(start[0], start[1], 0, h);
    start_node.parent = nullptr;
    open_set.push_back(&start_node);

    
    while(!open_set.empty())
    {
        
        // Sort the nodes in the open set
        sortSet(open_set); 

        // Get current node (last one) and remove it from open set
        // Problem: The current node gets removed from open set but then gets back in I think
        auto current_node = open_set.back();
        open_set.pop_back();

        // Put current node in the closed set
        closed_set.push_back(current_node);

        // Check if it's the end node
        if (current_node->x == end[0] && current_node->y == end[1])
        {
            // Reverse back the Node to get back to origin
            output = SearchBack(current_node);

            return output;
        }
        else
        {
            // Get neighbors of current node and put them in open set
            ExpandNeighbors(current_node, map, open_set, closed_set, end);
        }

    }

    std::cout << "Not path found" << std::endl;

    return output;
}

void Astar::StepSearch(int map[20][25], int start[2], int end[2])
{

    // If path is already found, don't do anything
    if (search_complete == false)
    {

        // Step search initialization
        if (stepSearchInitialized == false)
            {
                std::cout << "Initialize step search" << std::endl;

                // Initialize closed set and open set
                closed_set_step_search = {};
                open_set_step_search = {};

                // Create first node
                float h_first_node = Node::heurestic(start[0], start[1], end[0], end[1]);

                // Allocate start node dynamically
                Node* start_node = new Node(start[0], start[1], 0, h_first_node);
                start_node->parent = nullptr;

                // Add first node to open set
                open_set_step_search.push_back(start_node);

                stepSearchInitialized = true;
            }
            else
            {

                // Sort the nodes in the open set
                sortSet(open_set_step_search); 

                // Get current node (last one in the open set)
                auto current_node = open_set_step_search.back();

                // Remove the current node from the open set
                open_set_step_search.pop_back();

                // Put current node in the closed set
                closed_set_step_search.push_back(current_node);

                // Check if the current node is the end node
                if (current_node->x == end[0] && current_node->y == end[1])
                {
                    // Reverse back the Node to get back to origin to create the full path
                    current_path = SearchBack(current_node);

                    std::cout << "Goal node found" << std::endl;

                    search_complete = true;
                }
                else
                {
                    // Get neighbors of current node and put them in open set
                    ExpandNeighbors(current_node, map, open_set_step_search, closed_set_step_search, end);
                }
            }
    }
}