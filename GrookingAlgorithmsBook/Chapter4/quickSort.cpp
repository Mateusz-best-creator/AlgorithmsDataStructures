#include <iostream>
#include <vector>

int partition(std::vector<int>& data, int left, int right) 
{
    int pivot = data[right];
    int i = left - 1;

    for (int j = left; j < right; j++) 
    {
        if (data[j] <= pivot) 
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

void quickSort(std::vector<int>& data, int left, int right) 
{
    if (left >= right)
        return;

    int pivotIndex = partition(data, left, right);
    quickSort(data, left, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, right);
}

int main()
{
    std::vector<int> data{10, 100, 5, 20, -5, 4, 1, 8, 30, 25};
    quickSort(data, 0, data.size() - 1);
    for (const auto& e : data)
        std::cout << e << " ";
    std::cout << std::endl;
}
