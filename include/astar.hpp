#pragma once
#include <vector>
#include <iostream>
#include "Node.hpp"
#include<algorithm>
#include<memory>

class Astar {

public:

    Astar();
    ~Astar();

    std::vector<std::vector<int>> search(int map[20][25], int start[2], int end[2]);

    static void sortSet(std::vector<std::unique_ptr<Node>>& set);
    static bool Compare(const std::unique_ptr<Node>& node1, const std::unique_ptr<Node>& node2);
    static bool CheckValidNode(int x, int y, int map[20][25]);
    static void ExpandNeighbors(Node* current_node, int map[20][25], std::vector<std::unique_ptr<Node>> &open_set, std::vector<std::unique_ptr<Node>> &closed_set, int end[2]);
    static std::vector<std::vector<int>> SearchBack(const Node& current_node);
    static Node* GetNodeFromOpenSet(int x, int y, std::vector<std::unique_ptr<Node>> &open_set);
    static bool NodeInClosedSet(int x, int y, std::vector<std::unique_ptr<Node>> &closed_set);
    
    // For step search
    bool stepSearchInitialized = false;
    void StepSearch(int map[20][25], int start[2], int end[2]);
    // std::vector<Node*> closed_set_step_search;
    // std::vector<Node*> open_set_step_search;

    std::vector<std::unique_ptr<Node>> closed_set_step_search;
    std::vector<std::unique_ptr<Node>> open_set_step_search;

    // std::vector<std::shared_ptr<Node>> closed_set_step_search;
    // std::vector<std::shared_ptr<Node>> open_set_step_search;

    std::vector<int*> test_set;
    bool search_complete;
    int test;
    std::vector<std::vector<int>> current_path;

    void showPrint();

};