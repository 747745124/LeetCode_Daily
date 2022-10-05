#include "header.hpp"
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> presences;
        for (const auto &num : nums)
        {
            presences[num]++;
        }

        for (auto &kv : presences)
        {
            kv.second *= kv.first;
        }
    }
};