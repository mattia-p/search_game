#pragma once
#include <cmath>

class Node{

public:

    Node(int x, int y, int g, float h);
    ~Node();

    static float heurestic(int x1, int y1, int x2, int y2);

    int x;
    int y;
    int g; // Cost to get to node
    int h; // heurestic
    Node* parent;

};