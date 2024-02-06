#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> data[i];
    }

    int lewa[n], prawa[n], max = -1, local = 0, prawaMaxIndex = 0, lewaMaxIndex = 0;
    lewa[0] = prawa[n - 1] = 0;
    for (int i = 1; i < n; i++)
    {
        local = std::max(data[i], data[i] + local);
        max = std::max(max, local);
        lewa[i] = max;
        if (max > lewa[lewaMaxIndex])
        {
            lewaMaxIndex = i;
        }
    }
    max = local = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        local = std::max(data[i], data[i] + local);
        max = std::max(max, local);
        prawa[i] = max;
        if (max >= prawa[prawaMaxIndex])
        {
            prawaMaxIndex = i;
        }
    }

    int bIndex = 1;
    for (int i = prawaMaxIndex + 1; i < lewaMaxIndex; i++)
    {
        if (data[i] < data[bIndex])
            bIndex = i;
    }
    int sum = 0;
    for (int i = prawaMaxIndex + 1; i < bIndex; i++)
        sum += data[i];
    for (int i = bIndex + 1; i < lewaMaxIndex; i++)
        sum += data[i];

    //std::cout << prawaMaxIndex << ", " << lewaMaxIndex << ", " << bIndex << std::endl;
    std::cout << sum << std::endl;
}