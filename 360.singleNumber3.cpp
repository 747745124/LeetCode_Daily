#include "header.hpp"
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> res;
        unordered_map<int, int> presence;
        for (const auto &num : nums)
        {
            presence[num]++;
        }

        for (const auto &kv : presence)
        {
            if (kv.second == 1)
                res.push_back(kv.first);
        }

        return res;
    }
};