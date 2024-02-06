#include <iostream>

const int base = 1<<3;

class SegmentTree
{
private:
    int tree[base * 2];

public:
    SegmentTree()
    {
        for (int i = 0; i < base * 2; i++)
            tree[i] = 0;
    }

    void update(int index, int newValue)
    {
        index += base;
        tree[index] = newValue;
        index /= 2;
        while (index > 0)
        {
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
            index /= 2;
        }
    }

    void query(int a, int b)
    {
        int left = a - 1 + base;
        int right = b + 1 + base;
        int result = 0;
        while (left / 2 != right / 2)
        {
            if (left % 2 == 0)
                result += tree[left + 1];
            if (right % 2 == 1)
                result += tree[right - 1];
            left /= 2;
            right /= 2;
        }

        std::cout << "Suma na przedziale " << a << ", " << b << " = " << result << std::endl;
    }
};

int main()
{
    SegmentTree tree;
    tree.update(5, 10);
    tree.update(6, -5);
    tree.update(7, 5);
    tree.update(3, 3);
    tree.query(3, 7);
}