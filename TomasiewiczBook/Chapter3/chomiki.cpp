#include <iostream>
#include <vector>
#include <map>

int main()
{
    int n, m, temp;
    std::cin >> n >> m;
    
    std::map<int, std::vector<int>> sums;

    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        for (int j = 1; j <= 5; j++)
        {
            if (i == 0)
            {
                sums[j].push_back(0);
            }
            else
            {
                sums[j].push_back(sums[j][i - 1]);
            }
        }
        sums[temp][i]++;
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < sums[i].size(); j++)
        {
            std::cout << sums[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
    
    int a, b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        for (int j = 1; j <= 5; j++)
        {
            if (sums[j][a - 1] != sums[j][b - 1] || (sums[j][a - 1] > 0 && a - 1 == 0))
            {
                std::cout << j << std::endl;
                break;
            }
        }
    }
    
}