#include <iostream>
#include <vector>

int partition(std::vector<int>& vector, int left, int right)
{
    int pivot = vector[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (vector[j] < pivot)
        {
            i++;
            std::swap(vector[i], vector[j]);
        }
    }
    std::swap(vector[i + 1], vector[right]);
    return i + 1;
}

void quickSort(std::vector<int>& vector, int left, int right)
{
    if (left >= right)
        return;
    int pivotIndex = partition(vector, left, right);
    quickSort(vector, left, pivotIndex - 1);
    quickSort(vector, pivotIndex + 1, right);
}

int main()
{
    std::vector<int> data{30, 10, 60, 70, 40, 20};
    quickSort(data, 0, data.size() - 1);
    for (const auto& e : data)
        std::cout << e << " ";
    std::cout << std::endl;
}