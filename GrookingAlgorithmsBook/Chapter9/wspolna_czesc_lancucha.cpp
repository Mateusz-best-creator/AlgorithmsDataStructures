#include <iostream>
#include <string>


int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int result = 0;
    int array[s1.size()][s2.size()];

    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] != s2[j])
            {
                if (i > 0 && j > 0)
                    array[i][j] = std::max(array[i - 1][j], array[i][j - 1]);
                else if (i > 0)
                    array[i][j] = array[i - 1][j];
                else if (j > 0)
                    array[i][j] = array[i][j - 1];
            }
            else
            {
                if (i == 0)
                    array[i][j] = 1;
                else
                    array[i][j] = array[i - 1][j - 1] + 1;
            }
            result = std::max(result, array[i][j]);
        }
    }

    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Najdluzszy wspolna podsekwencja: " << result << std::endl;
}