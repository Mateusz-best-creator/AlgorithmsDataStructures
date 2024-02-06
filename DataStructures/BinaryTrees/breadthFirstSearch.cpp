#include <iostream>
#include <vector>
#include <deque>


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

    std::deque<Node*> values;
    std::vector<char> result;

    values.push_back(&a);
    while (values.size() > 0)
    {
        Node* temp = values.back();
        result.push_back(temp->value);
        values.pop_back();
        if (temp->left)
            values.push_front(temp->left);
        if (temp->right)
            values.push_front(temp->right);
    }

    for (const auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;
}