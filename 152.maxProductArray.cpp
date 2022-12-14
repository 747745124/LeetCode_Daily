#include "header.hpp"
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int res = max_so_far;

        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            int temp = min(curr, min({min_so_far * nums[i], max_so_far * nums[i]}));
            max_so_far = max(curr, max({max_so_far * nums[i], min_so_far * nums[i]}));
            min_so_far = temp;

            res = max(res, max_so_far);
        }

        return res;
    }
};