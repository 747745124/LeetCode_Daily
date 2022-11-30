#include "header.hpp"
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_current = 0;
        int max_global = 0;
        for (const auto &num : nums)
        {
            max_current = max(max_current + num, num);
            max_global = max(max_current, max_global);
        }

        return max_global;
    }
};