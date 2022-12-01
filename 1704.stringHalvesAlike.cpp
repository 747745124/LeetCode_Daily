#include "header.hpp"
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int n = s.length();
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int num_1 = 0;
        int num_2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(vowels.begin(), vowels.end(), tolower(s[i], std::locale())) == vowels.end())
                continue;

            if ((i < n / 2))
            {
                num_1 += 1;
            }
            else
            {
                num_2 += 1;
            }
        }

        return num_1 == num_2;
    }
};