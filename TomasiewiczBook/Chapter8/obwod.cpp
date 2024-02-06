#include <iostream>
#include <vector>

void obwod(int n)
{
    std::vector<int> dzielniki;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            dzielniki.push_back(i);
            dzielniki.push_back(n / i);
        }
    }

    std::cout << dzielniki[dzielniki.size() - 1] * 2 + dzielniki[dzielniki.size() - 2] * 2 << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    obwod(n);
}