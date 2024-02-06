#include <iostream>
#include <vector>


int main()
{
    int n, temp, index = 0;
    std::cin >> n;
    int stack[n];
    std::vector<int> data(n);
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

    // We assume that their is always a leader
    int lider = stack[0];

    int values[n + 1];
    values[0] = 0;
    for (int i = 0; i < data.size(); i++)
    {
        int isLider = (data[i] == lider ) ? 1 : 0;
        values[i + 1] = values[i] + isLider;
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (values[i] - values[0] > (i - 1) / 2 && values[n] - values[i + 1] > (n - 1 - i) / 2)
            result++;
    }
    std::cout << result << std::endl;
}