#include <iostream>
#include <set>

int main()
{
    int n, m, temp;
    std::cin >> n >> m;
    std::set<int> set;
    for (int i = 0; i < m; i++)
    {
        std::cin >> temp;
        if (temp > n)
            continue;
        set.insert(temp);
        if (set.size() == n)
        {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
}