#include <iostream>
#include <vector>

void binarySearch(std::vector<int> data, int value)
{
    int left = 0, right = data.size() - 1, middle;
    while (left <= right)
    {
        middle = (right + left) / 2;
        if (data[middle] == value)
        {
            std::cout << value << " is at index " << middle << std::endl;
            return;
        }
        else if (data[middle] > value)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    std::cout << value << " is not here\n";
}

int main()
{
    std::vector<int> vector{1,2,2,2,3,4,5,5,6,7,8,9,9,10,10};
    binarySearch(vector, 3);
}