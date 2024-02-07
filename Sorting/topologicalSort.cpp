#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <array>

void topologicalSort(std::map<int, std::vector<int>> map)
{
    std::map<int, int> edges;
    std::deque<int> deque;
    std::vector<int> result;
    
    for (const auto [key, values] : map)
    {
        if (!edges[key])
            edges[key] = 0;
        for (auto value : values)
        {
            edges[value]++;
        }
    }
    for (auto [key, value] : edges)
    {
        if (value == 0)
            deque.push_back(key);
     }

    while (deque.size())
    {
        int temp = deque.front();
        deque.pop_front();
        result.push_back(temp);

        for (auto value : map[temp])
        {
            edges[value]--;
            if (edges[value] == 0)
                deque.push_back(value);
        }
    }

    for (auto v : result)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main()
{
    std::map<int, std::vector<int>> map;

    map[0].push_back(2);
    map[0].push_back(3);
    map[0].push_back(6);

    map[9].push_back(2);
    map[9].push_back(10);
    
    map[2].push_back(6);
    
    map[10].push_back(6);
    
    map[6].push_back(7);
    map[6].push_back(11);

    map[11].push_back(12);

    map[12].push_back(8);
    
    map[7].push_back(12);
    map[7].push_back(4);
    
    map[4].push_back(5);
    map[4].push_back(8);
    
    map[3].push_back(1);
    map[3].push_back(4);
    
    map[1].push_back(4);

    topologicalSort(map);
    //for (auto e : result)
      //  std::cout << e << " ";
    std::cout << std::endl;
}