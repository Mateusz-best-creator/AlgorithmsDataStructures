#include <iostream>

void countDown(int n)
{
    if (n <= 0)
        return;
    std::cout << n << std::endl;
    countDown(n - 1);
}

void countUp(int n)
{
    if (n <= 0)
        return;
    countUp(n - 1);
    std::cout << n << std::endl;
}

int main()
{
    countDown(10);
    std::cout << "\n=============\n\n";
    countUp(10);
}