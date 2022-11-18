#include "header.hpp"
class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        vector<int> change(length, 0);
        for (auto &update : updates)
        {
            int start = update[0], end = update[1], inc = update[2];

            change[start] += inc;
            if (end < length - 1)
                change[end + 1] -= inc;
        }

        for (int i = 1; i < length; i++)
        {
            change[i] += change[i - 1];
        }

        return change;
    }
};