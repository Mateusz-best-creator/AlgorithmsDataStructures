#include <iostream>
#include <vector>

void merge(std::vector<int>& leftData, std::vector<int>& rightData, std::vector<int>& originalData)
{
    int i = 0, j = 0, k = 0;
    while (i < leftData.size() && j < rightData.size())
    {
        if (leftData[i] < rightData[j])
        {
            originalData[k] = leftData[i];
            i++;
        }
        else
        {
            originalData[k] = rightData[j];
            j++;
        }
        k++;
    }

    while (i < leftData.size())
    {
        originalData[k] = leftData[i];
        i++;
        k++;
    }
    while (j < rightData.size())
    {
        originalData[k] = rightData[j];
        j++;
        k++;
    }
}


void mergeSort(std::vector<int>& vector)
{
    if (vector.size() <= 1)
        return;

    int middle = vector.size() / 2;
    std::vector<int> leftData, rightData;
    for (int i = 0; i < vector.size(); i++)
    {
        if (i < middle)
            leftData.push_back(vector[i]);
        else
            rightData.push_back(vector[i]);
    }

    mergeSort(leftData);
    mergeSort(rightData);
    merge(leftData, rightData, vector);
}

int main()
{
    std::vector<int> data{30, 10, 60, 70, 40, 20};
    mergeSort(data);
    for (const auto& e : data)
        std::cout << e << " ";
    std::cout << std::endl;
}