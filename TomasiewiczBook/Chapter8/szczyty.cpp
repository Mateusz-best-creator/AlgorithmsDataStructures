#include <iostream>
#include <vector>

std::vector<int> licz(int n)
{
    std::vector<int> dzielniki;
    dzielniki.push_back(n);
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            dzielniki.push_back(i);
            dzielniki.push_back(n / i);
        }
    }
    return dzielniki;
}

bool hasFlag(int dzielnik, std::vector<int> data)
{
    int index = 0;
    bool flag = false;
    for (int i = 0; i < data.size() / dzielnik; i++)
    {
        for (int j = 0; j < dzielnik; j++)
        {
            if (index == 0 || index == data.size() - 1)
            {
                index++;
                continue;
            }
            if (data[index - 1] < data[index] && data[index + 1] < data[index])
            {
                index++;
                flag = true;
                break;
            }
            index++;
        }
        if (flag == false)
            return false;
        flag = false;
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n);

    for (int i = 0; i < n; i++)
        std::cin >> data[i];

    std::vector<int> dzielniki;
    dzielniki = licz(n);

    int maxFlags = -1;

    for (const auto& dzielnik : dzielniki)
    {
        if (maxFlags < n / dzielnik && hasFlag(dzielnik, data))
            maxFlags = n / dzielnik;
    }

    std::cout << maxFlags << std::endl;
}