#include <iostream>
#include <vector>


int main()
{
    int n = 100;
    std::vector<int> factor(n, 0);

    for (int i = 2; i * i < n; i++)
    {
        if (factor[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                factor[j] = i;
            }     
        }
    }

    //for (int i = 0; i < 20; i++)
        //std::cout << factor[i] << " ";

    int liczba;
    std::cin >> liczba;
    if (factor[liczba] == 0)
    {
        std::cout << "NIE\n";
        return 0;
    }
    int temp = liczba / factor[liczba];
    if (factor[temp] == 0 && factor[liczba / temp] == 0)
        std::cout << "TAK\n";
    else
        std::cout << "NIE\n";
}