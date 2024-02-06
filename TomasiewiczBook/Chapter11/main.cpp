#include <iostream>
#include <vector>
#include <map>

void fib(int n)
{
    int array[2]{0, 1};
    for (int i = 2; i < n; i++)
    {
        int temp = array[1];
        array[1] = array[0] + array[1];
        array[0] = temp;
    }
        
    std::cout << "fib(" << n << ") = " << array[1] << std::endl;
}

const int SIZE = 10;

void binarySearch(int array[SIZE], int x)
{
    int left = 0, right = SIZE - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (array[middle] == x)
        {
            std::cout << "Value " << x << " is at index " << middle << std::endl; 
            return;
        }
        if (array[middle] > x)
            right = middle - 1;
        else 
            left = middle + 1;
    }
    std::cout << "Value " << x << " not found\n";
}

void suma_2(int x, const std::vector<int>& vector = {1, 3, 4, 6, 7, 8, 9, 12})
{
    std::map<int, int> mapa;
    for (int i = 0; i < vector.size(); i++)
    {
        int dif = x - vector[i];
        if (mapa[dif] == 1)
        {
            std::cout << "(" << vector[i] << ", " << dif << ")\n";
        }
        mapa[vector[i]] = 1;
    }
}

void suma_3(int found, const std::vector<int>& vector = {1, 2, 2, 6, 4, 0, 7, 3, 9, 1, 0, 10})
{
    for (int x = 0; x < vector.size() - 2; x++)
    {
        for (int y = x + 1; y < vector.size() - 1; y++)
        {
            int z = y + 1;
            while (z < vector.size() && vector[x] + vector[y] + vector[z] == found)
            {
                std::cout << vector[x] << ", " << vector[y] << ", " << vector[z] << std::endl;
                z++;
            }
        }
    }
}

int tablica[100000];


void suma_prefiksowa()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << "Na przedziale " << a << ", " << b << " suma to = " << tablica[b] - tablica[a - 1] << std::endl;
}

int main(int argc, char* argv[])
{
    //fib(7);
    //int ar[SIZE]{ 1,2,3,4,5,6,7,8,9,10 };
    //binarySearch(ar, 9);
    //suma_2(10);
    //suma_3(10);


    tablica[0] = 0;
    for (int i = 1; i < 100000; i++)
    {
        tablica[i] = tablica[i - 1] + i;
    }
    
    suma_prefiksowa();
}