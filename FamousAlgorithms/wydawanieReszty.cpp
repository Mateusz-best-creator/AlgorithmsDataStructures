#include <iostream>
#include <map>

void reszta_1()
{
    int coins[4] {1, 3, 4, 5};
    int n;
    std::cin >> n;
    int result = 0, sum = 0;
    
    int i = 3;
    while (n > 0 && i >= 0)
    {
        if (coins[i] <= n)
        {
            result++;
            n -= coins[i];
            std::cout << coins[i] << " ";
        }
        else
        {
            i--;
        }
    }
    std::cout << "\nResult = " << result << std::endl;
}

void reszta_2()
{
    int coins[4] {1, 3, 4, 5};
    int n, result = 0;
    std::cin >> n;
    std::map<int, int> map;
    map[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int min = -1;
        for (int j = 0; j < sizeof(coins) / sizeof(coins[0]); j++)
        {
            if (coins[j] > i)
                break;
            else if (coins[j] == i)
            {
                min = 1;
                break;
            }
            else
            {
                if (min == -1)
                    min = 1 + map[i - coins[j]];
                else
                    min = std::min(min, 1 + map[i - coins[j]]);
            }
        }
        map[i] = min;
        min = -1;
    }

    //for (auto [key, value] : map)
    //    std::cout << key << ": " << value << std::endl;
    
    std::cout << n << " = " << map[n] << std::endl;
}

int main()
{
    reszta_2();
}