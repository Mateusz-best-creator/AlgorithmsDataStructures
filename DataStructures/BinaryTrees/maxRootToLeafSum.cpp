#include <iostream>
#include <vector>
#include <stack>

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(char val)
        : value(val), left(nullptr), right(nullptr) {}
};

int maxPathSum(int& max, int& local, Node* node);

int main()
{
    Node a(3);
    Node b(4);
    Node c(11);
    Node d(4);
    Node e(2);
    Node f(1);


    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    /*
        Note: for path finding things, usually recursion approach works pretty well.
    */
    int max = -1, local = 0;
    max = maxPathSum(max, local, &a);
    std::cout << "Max value path = " << max << std::endl;
}

int maxPathSum(int& max, int& local, Node* node)
{
    local += node->value;
    if (!node->left && !node->right)
    {
        max = std::max(max, local);
        local -= node->value;
        return max;
    }
    if (node->left)
        max = maxPathSum(max, local, node->left);
    if (node->right)
        max = maxPathSum(max, local, node->right);

    local -= node->value;
    return max;
}
