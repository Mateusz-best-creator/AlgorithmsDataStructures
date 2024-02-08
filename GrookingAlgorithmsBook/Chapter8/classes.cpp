#include <iostream>
#include <string>
#include <vector>

struct Lesson
{
    std::string name;
    float start, end;
};

int main()
{
    std::vector<Lesson> lessons;
    lessons.push_back({"Plastyka", 9.0, 10.0});
    lessons.push_back({"Angielski", 9.5, 10.5});
    lessons.push_back({"Matematyka", 10.0, 11.0});
    lessons.push_back({"Informatyka", 10.5, 11.5});
    lessons.push_back({"Muzyka", 11.0, 12.0});

    std::vector<Lesson> result;
    int previous;
    for (int i = 0; i < lessons.size(); i++)
    {
        if (i == 0)
        {
            previous = 0;
            result.push_back(lessons[i]);
        }
        else if (lessons[i].start >= lessons[previous].end)
        {
            previous = i;
            result.push_back(lessons[i]);
        }
    }
    for (auto lesson : result)
    {
        std::cout << lesson.name << ", " << lesson.start << ", " << lesson.end << std::endl; 
    }
}