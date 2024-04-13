#include <gtest/gtest.h>
#include "Node.hpp"

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
