#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data{ 10, 5, 20, 3, 7, 19, 0, 4 };
    std::vector<int> result;

    for (int i = 0; i < data.size(); i++)
    {
        int min = 1e8, minIndex = -1;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == -1)
                continue;
            if (min > data[i])
            {
                min = data[i];
                minIndex = i;
            }
        }
        result.push_back(min);
        data[minIndex] = -1;
    }

    for (const auto& num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}