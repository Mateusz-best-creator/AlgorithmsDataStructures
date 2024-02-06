#include <iostream>
#include <vector>
#include <map>

void podejscie_1()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        std::cin >> numbers[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (numbers[i] % numbers[j] != 0)
                sum++;
        }
        std::cout << sum << " ";
        sum = 0;
    }
    std::cout << std::endl;
}

void podejscie_2()
{
    std::map<int, int> map;
    int temp, n, max = -1;
    std::cin >> n;
    std::vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if (max < temp)
            max = temp;
        map[temp]++;
        data[i] = temp;
    }
    std::vector<int> stos(max);
    for (const auto& [key, value] : map)
    {
        for (int i = key - 1; i < stos.size(); i += key)
        {
            stos[i] += value;
        }
    }
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << n - stos[data[i] - 1] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //podejscie_1();
    podejscie_2();
}