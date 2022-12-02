#include "header.hpp"
class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        int pos[26] = {0};
        for (int i = 0; i < 26; i++)
        {
            pos[keyboard[i] - 'a'] = i;
        }

        int res = pos[word[0] - 'a'];
        for (int i = 0; i < word.length() - 1; i++)
        {
            int distance = abs(pos[word[i + 1] - 'a'] - pos[word[i] - 'a']);
            res += distance;
        }

        return res;
    }
};
