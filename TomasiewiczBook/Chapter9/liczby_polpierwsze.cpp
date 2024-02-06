#include <iostream>
#include <vector>

bool czyPolPierwsza(const std::vector<int>& vector, const int& liczba)
{
    if (vector[liczba] == 0)
        return false;
    int temp = liczba / vector[liczba];
    if (vector[temp] == 0 && vector[liczba / temp] == 0)
        return true;
    return false;
}

int SIZE = 40;

int main()
{
    std::vector<int> vector(SIZE, 0);
    std::vector<int> sums(SIZE, 0);
    for (int i = 2; i * i < SIZE; i++)
    {
        if (vector[i] == 0)
        {
            for (int j = i * i; j < SIZE; j += i)
            {
                if (vector[j] == 0)
                {
                    vector[j] = i;
                }                    
            }
        }
    }

    for (int i = 1; i < SIZE; i++)
    {
        if (czyPolPierwsza(vector, i))
            sums[i] = sums[i - 1] + 1;
        else
            sums[i] = sums[i - 1];
    }

    int t, a, b;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> a >> b;
        std::cout << sums[b] - sums[a - 1] << std::endl;
    }
}