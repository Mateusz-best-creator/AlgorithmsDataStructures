#include <iostream>
#include <vector>
#include <map>

void backpack()
{
    std::vector<int> values {0, 2, 2, 4, 5, 3};
    std::vector<int> weights {0, 3, 1, 3, 4, 7};
    int capacity = 7;

    int array[values.size()][capacity + 1];
    // First row full of zeros
    for (int i = 0; i <= capacity; i++) array[0][i] = 0;   
    for (int row = 1; row < values.size(); row++)
    {
        for (int column = 0; column <= capacity; column++)
        {
            if (weights[row] > column)
                array[row][column] = array[row - 1][column];
            else
            {
                array[row][column] = std::max(values[row] + array[row - 1][column - weights[row]], array[row - 1][column]);
            }
        }
    }

    for (int row = 0; row < values.size(); row++)
    {
        for (int column = 0; column <= capacity; column++)
        {
            std::cout << array[row][column] << " ";
        }
        std::cout << std::endl;
    }

    std::map<int, int> includedItems;
    int row = values.size() - 1, column = capacity;
    int maxValue = array[row][column];
    std::cout << "Max value is = " << maxValue << std::endl;

    while (array[row][column] != 0)
    {
        if (array[row][column] == array[row - 1][column])
            row--;
        else
        {
            includedItems[weights[row]] = values[row];
            column -= weights[row];
            row--;
        }
    }

    std::cout << "Items included in backpack: \n";
    for (const auto& [key, value] : includedItems)
        std::cout << "Weight = " << key << " Value = " << value << "\n";
}

int main()
{
    backpack();
}