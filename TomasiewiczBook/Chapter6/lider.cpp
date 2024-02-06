#include <iostream>
#include <vector>

int main()
{
    int n, temp, index = 0;
    std::cin >> n;
    std::vector<int> data(n);
    int stack[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        data[i] = temp;
        if (index == 0)
            stack[index++] = temp;
        else if (stack[index - 1] != temp)
            index--;
        else
        {
            stack[index++] = temp;
        }
    }

    if (index == 0)
    {
        std::cout << "There is no lider\n";
        return 0;
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] == stack[0])
            counter++;
    }
    std::cout << "Counter: " << counter << std::endl;
    if (counter > n / 2)
        std::cout << "Lider is: " << stack[0] << std::endl;
    else
        std::cout << "There is no lider\n";
}