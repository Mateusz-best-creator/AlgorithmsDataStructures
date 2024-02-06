#include <iostream>
#include <vector>


struct Node
{
    char value;
    Node* left;
    Node* right;

    Node(char val)
        : value(val), left(nullptr), right(nullptr) {}
};

int main()
{
    Node a('a');
    Node b('b');
    Node c('c');
    Node d('d');
    Node e('e');
    Node f('f');

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    std::vector<Node*> values;
    std::vector<char> result;

    values.push_back(&a);
    while (values.size() > 0)
    {
        Node* last = values.back();
        result.push_back(last->value);
        values.pop_back();
        if (last->right)
            values.push_back(last->right);
        if (last->left)
            values.push_back(last->left);
    }
    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;
}