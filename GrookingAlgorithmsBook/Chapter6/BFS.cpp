#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <deque>


int BFS(std::map<std::string ,std::vector<std::string>> map)
{
    int result = 0;
    
    std::map<std::string, bool> visited;
    std::map<std::string, int> distance;

    std::deque<std::string> deque;
    
    deque.push_back("Ja");
    visited["Ja"] = false;
    distance["Ja"] = 0;

    while (deque.size())
    {
        std::string temp = deque.front();
        deque.pop_front();
        if (!visited[temp])
        {
            visited[temp] = true;
            if (temp[temp.size() - 1] == 'M')
            {
                return distance[temp];
            }
            else
            {
                for (int i = 0; i < map[temp].size(); i++)
                {
                    deque.push_back(map[temp][i]);
                    distance[map[temp][i]] = distance[temp] + 1;
                }
            }
        }
    }
    // Target not found
    return -1;
}

int main()
{
    std::map<std::string, std::vector<std::string>> map;
    map["Ja"].push_back("Mateusz");
    map["Ja"].push_back("Ola");
    map["Ja"].push_back("Agnieszka");
    map["Agnieszka"].push_back("Krzysztof");
    map["Agnieszka"].push_back("Stasia");
    map["Stasia"].push_back("ZdzislawM");
    map["Krzysztof"].push_back("Ola");
    map["Krzysztof"].push_back("Mateusz");
    map["Mateusz"].push_back("Ja");

    // Szukamy imienia ktore konczy sie na "M"
    int najkrotszaDroga = BFS(map);
    std::cout << "Najkrotsza droga: " << najkrotszaDroga << std::endl;
}