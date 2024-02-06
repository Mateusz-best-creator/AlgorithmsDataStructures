#include <iostream>

int main()
{
    int n, temp, result = 0;
    std::cin >> n;
    int zachod = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if (temp == 0)
            zachod++;
        else
        {
            result += zachod;
            std::cout << result << std::endl;
        }
    }
    std::cout << result << "\n";
}