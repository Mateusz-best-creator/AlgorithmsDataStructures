#include <iostream>
#include <vector>


int main()
{
    int n, m, temp;
    std::cin >> n >> m;
    std::vector<int> data(n, 0);

    int maksimum = 0, minimum = -1;

    for (int i = 0; i < m; i++)
    {
        std::cin >> temp;
        if (temp == n + 1)
        {
            minimum = maksimum;
        }   
        else
        {
            data[temp - 1] = std::max(minimum, data[temp - 1]) + 1;
            maksimum = std::max(maksimum, data[temp - 1]);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << std::max(minimum, data[i]) << " ";
}