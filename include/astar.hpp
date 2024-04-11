#pragma once
#include <vector>
#include <iostream>
#include "Node.hpp"
#include<algorithm>

class Astar {

public:

    Astar();
    ~Astar();

    std::vector<std::vector<int>> search(int map[20][25], int start[2], int end[2]);

    static void sortSet(std::vector<Node*> &set);
    static bool Compare(const Node* node1, const Node* node2);
    static bool CheckValidNode(int x, int y, int map[20][25]);
    static void ExpandNeighbors(Node* &current_node, int map[20][25], std::vector<Node*> &open_set, int end[2]);
    static std::vector<std::vector<int>> SearchBack(Node* &current_node);
    static Node* GetNodeFromOpenSet(int x, int y, std::vector<Node*> &open_set);
};