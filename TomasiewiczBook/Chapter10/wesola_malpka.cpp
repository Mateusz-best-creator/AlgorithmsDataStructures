#include <iostream>

int nwd(int a, int b)
{
    if (a % b == 0)
        return b;
    return nwd(b, a % b);
}

int nww(int a, int b)
{
    return a * b / nwd(a, b);
}

int main()
{
    int n, dlugosc, t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n >> dlugosc;
        int result = nww(n, dlugosc) / dlugosc;
        std::cout << result; 
    }
}