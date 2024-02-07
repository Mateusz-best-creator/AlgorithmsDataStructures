#include <iostream>
#include <queue>
#include <vector>
#include <map>

struct Node
{
    int fromIndex;
    int toIndex;
    int cost;

    Node(int from, int to, int value)
        : fromIndex(from), toIndex(to), cost(value) {}
};

void lazy_dijkstra()
{
    std::vector<Node> data;
    data.push_back(Node(0, 1, 4));
    data.push_back(Node(0, 2, 1));
    data.push_back(Node(2, 1, 2));
    data.push_back(Node(1, 3, 1));
    data.push_back(Node(2, 3, 5));
    data.push_back(Node(3, 4, 3));

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> queue;
    int distances[5]{ 0, -1, -1, -1, -1 };
    bool visited[5]{ false, false, false, false, false };

    queue.push({0, 0});
    while (queue.size() > 0)
    {
        auto pair = queue.top();
        queue.pop();
        int index = pair.first, minValue = pair.second;
        visited[index] = true;

        if (distances[index] == -1 || distances[index] > minValue)
            distances[index] = minValue + 1;
        
    }
}

int main()
{
    lazy_dijkstra();
}