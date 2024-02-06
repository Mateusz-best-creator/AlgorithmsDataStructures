#include <iostream>

int licz(int liczba)
{
    int i, suma = 0;
    for (i = 1; i * i < liczba; i++)
    {
        if (liczba % i == 0)
            suma += 2;
    }
    if (i * i == liczba)
        suma++;
    std::cout << suma << std::endl;
    return suma;
}

int main()
{
    int monety[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int n = 10;
    int dzielniki[10];
    for (int i = 0; i < 10; i++)
    {
        int temp = licz(i + 1);
        if (temp  % 2 == 0)
            monety[i] = 0;
        else
            monety[i] = 1;
    }

    for (int i = 0; i < n; i++)
        std::cout << monety[i] << " ";
    std::cout << std::endl;
}