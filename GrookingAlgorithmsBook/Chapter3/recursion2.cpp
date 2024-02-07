#include <iostream>
#include <vector>

int sum(std::vector<int> data)
{
    if (data.size() == 1)
        return data[0];
    std::vector<int> remaining;
    for (int i = 1; i < data.size(); i++)
        remaining.push_back(data[i]);
    return data[0] + sum(remaining);
}

int sum2(std::vector<int> data)
{
    if (data.size() == 1)
        return data[0];
    if (data.size() == 0)
        return 0;

    int left = 0, right = data.size() - 1, middle = data.size() / 2;
    std::vector<int> leftData;
    std::vector<int> rightData;
    for (int i = 0; i < data.size(); i++)
    {
        if (i < middle) 
            leftData.push_back(data[i]);
        else
            rightData.push_back(data[i]);
    }
    return sum2(leftData) + sum2(rightData);
}

int binarySearch(std::vector<int> data, int x, int left, int right)
{
    int middle = (left + right) / 2;
    if (data.size() == 0)
        return -1;
    if (data[middle] == x)
        return middle;
    
    if (data[middle] > x)
        return binarySearch(data, x, 0, middle - 1);
    else
        return binarySearch(data, x, middle + 1, right);
}

int main()
{
    std::vector<int> data{ 10,20,30,40,50,60,70,80,90 };
    std::cout << sum(data) << std::endl;
    std::cout << sum2(data) << std::endl;

    std::cout << binarySearch(data, 80, 0, data.size() - 1) << std::endl;
}