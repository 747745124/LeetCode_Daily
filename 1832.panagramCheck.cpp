#include "header.hpp"
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        unordered_map<char, int> presence;
        for (auto &ch : sentence)
        {
            presence[ch]++;
        }

        if (presence.size() == 26)
            return true;
        return false;
    }
};