#include <iostream>
#include <stack>

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(char val)
        : value(val), left(nullptr), right(nullptr) {}
};

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

    int sum = 0, min = -1;
    std::stack<Node*> stack;
    stack.push(&a);
    while (stack.size() > 0)
    {
        Node* temp = stack.top();
        
        sum += temp->value;
        if (min == -1 || min > temp->value)
            min = temp->value;

        stack.pop();
        if (temp->left)
            stack.push(temp->left);
        if (temp->right)
            stack.push(temp->right);
    }
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Min value = " << min << std::endl;
}