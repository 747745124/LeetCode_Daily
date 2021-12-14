#include "header.hpp"
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> presence;
        for (const auto &num : nums)
        {
            if (presence[num] == 0)
                presence[num] = 1;
            else if (presence[num] == 1)
                presence[num] = 2;
            else
                presence.erase(num);
        }
        int res;
        for (auto &x : presence)
        {
            res = x.first;
        }
        return res;
    }
};