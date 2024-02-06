#include <iostream>

int nwd(int a, int b)
{
    while (a % b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int nww(int a, int b)
{
    return a * b / nwd(a, b);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << nwd(n, n - 1) + nww(n, n - 1) << std::endl;
}