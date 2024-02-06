#include <iostream>
#include <vector>

int main()
{
    const int n = 100;
    std::vector<bool> data(n + 1, true);

    for (int i = 2; i * i < n; i++)
    {
        if (data[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                data[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (data[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n\nFaktoryzacja\n\n";

    std::vector<int> factor(21, 0);
    for (int i = 2; i * i < 20; i++)
    {
        if (factor[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                factor[j] = i;
        }
    }

    for (int i = 2; i < 21; i++)
        std::cout << factor[i] << " ";
    std::cout << std::endl;
}