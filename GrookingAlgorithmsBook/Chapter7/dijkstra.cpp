#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits>

std::map<std::string, bool> processed;

std::string findLowestNode(const std::map<std::string, int>& costs)
{
    int lowestCost = INT_MAX; // Initialize to a large value
    std::string lowestCostNode = "unknown";
    for (const auto& [key, value] : costs)
    {
        if (value < lowestCost && !processed[key]) // Corrected condition
        {
            lowestCost = value;
            lowestCostNode = key;
        }
    }
    return lowestCostNode;
}


int main()
{
    // Creating the graph
    std::map<std::string, std::vector<std::map<std::string, int>>> graph;

    std::map<std::string, int> inner_map;
    inner_map["A"] = 6;
    inner_map["B"] = 2;

    std::vector<std::map<std::string, int>> inner_vector;
    inner_vector.push_back(inner_map);    
    graph["Start"] = inner_vector;

    inner_vector.clear();
    std::map<std::string, int> inner_map_2;
    inner_map_2["Meta"] = 1;
    inner_vector.push_back(inner_map_2);
    graph["A"] = inner_vector;

    inner_vector.clear();
    std::map<std::string, int> inner_map_3;
    inner_map_3["A"] = 3;
    inner_map_3["Meta"] = 5;
    inner_vector.push_back(inner_map_3);
    graph["B"] = inner_vector;

    // Creating costs map
    std::map<std::string, int> costs;
    costs["A"] = 6;
    costs["B"] = 2;
    costs["Meta"] = INT_MAX;

    // Creating parents map
    std::map<std::string, std::string> parents;
    parents["A"] = "Start";
    parents["B"] = "Start";
    parents["Meta"] = "unknown";

    std::string node = findLowestNode(costs);
    while (node != "unknown")
    {
        int cost = costs[node];
        auto neighbors = graph[node];
        for (const auto& hashTable : neighbors)
        {
            for (const auto& [key, value] : hashTable)
            {   
                int newCost = cost + value;
                if (costs[key] > newCost)
                {
                    costs[key] = newCost;
                    parents[key] = node;
                }
            }
        }
        processed[node] = true;
        node = findLowestNode(costs);
    }

    for (auto [key, value] : costs)
    {
        std::cout << "Key : " << value << std::endl;
    }

}