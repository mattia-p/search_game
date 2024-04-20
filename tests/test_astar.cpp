#include <gtest/gtest.h>
#include "Node.hpp"
#include "astar.hpp"

TEST(YourTestCaseName, YourTestName) {
    
    ASSERT_EQ(4, 4);  // Example assertion
}

TEST(Test_node, test_simple_node)
{
    int x = 1;
    int y = 2;
    float g = 0;
    float h = 10;
    // Node* node(x, y, g, h);
    Node* new_node = new Node(x, y, g, h);
    ASSERT_EQ(new_node->x, 1);
}


TEST(Test_node, test_heurestic)
{
    float h = Node::heurestic(1, 0, 0, 0);
    ASSERT_EQ(h, 1);
}


TEST(Test_node, test_get_node_from_open_set)
{
    Node* node1 = new Node(0, 0, 0, 0);
    Node* node2 = new Node(1, 1, 0, 0);
    Node* node3 = new Node(2, 3, 0, 0);
    Node* node4 = new Node(4, 5, 0, 0);

    std::vector<Node*> open_set = {node1, node2, node3, node4};

    int x = 1;
    int y = 0;
    Node* neighbor_node = Astar::GetNodeFromOpenSet(x, y, open_set);

    std::cout << neighbor_node << std::endl;

    ASSERT_EQ(nullptr, neighbor_node);
}

TEST(Test_node, test_get_node_from_open_set_2)
{
    Node* node1 = new Node(0, 0, 0, 0);
    Node* node2 = new Node(1, 1, 0, 0);
    Node* node3 = new Node(2, 3, 0, 0);
    Node* node4 = new Node(4, 5, 0, 0);

    std::vector<Node*> open_set = {node1, node2, node3, node4};

    int x = 0;
    int y = 0;
    Node* neighbor_node = Astar::GetNodeFromOpenSet(x, y, open_set);

    std::cout << neighbor_node << std::endl;

    ASSERT_EQ(node1, neighbor_node);
}

