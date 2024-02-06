#include <iostream>
#include <vector>

int result;

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> data[i];
    }

    int minimum = data[data.size() - 1] + 1;
    std::vector<bool> zamien(n, false);

    for (int i = n - 1; i >= 0; i--)
    {
        if (data[i] < minimum)
        {
            minimum = data[i];
            zamien[i] = true;
        }
    }

    int poz = -1;
    for (int i = 0; i < n; i++)
    {
        if (zamien[i])
        {
            result += (i - poz) * data[i];
            poz = i;
        }
    }

    std::cout << result << std::endl;
}