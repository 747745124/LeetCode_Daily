#include "header.hpp"
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> presences;
        int border = nums.size() / 2;
        for (const auto &num : nums)
        {
            presences[num] += 1;
            if (presences[num] > border)
                return num;
        }
    }
};