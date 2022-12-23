#include "header.hpp"
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int max_curr_0 = nums[0];
        int max_global_0 = INT32_MIN;

        int max_curr_1 = nums[1];
        int max_global_1 = INT32_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            max_curr_0 = max(max_curr_0 + nums[i], nums[i]);
            max_curr_1 = max(max_curr_1 + nums[(i + 1) % nums.size()], nums[(i + 1) % nums.size()]);

            max_global_0 = max(max_global_0, max_curr_0);
            max_global_1 = max(max_global_1, max_curr_1);
        }

        return max(max_global_0, max_global_1);
    }
};