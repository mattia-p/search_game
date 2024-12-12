#include "Node.hpp"


Node::Node(int x_in, int y_in, int g_in, float h_in)
{
    x = x_in;
    y= y_in;
    g = g_in;
    h = h_in;
}

Node::~Node(){}

float Node::heurestic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) * 2 + abs(y2 - y1) * 2;
}