#include "header.hpp"
class Solution
{
public:
    int twoSumLessThanK(vector<int> &nums, int k)
    {
        int i = 0;
        int j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int max_num = 0;
        while (i < j)
        {
            if ((nums[i] + nums[j]) < k)
            {
                max_num = max(nums[i] + nums[j], max_num);
                i++;
            }
            else
                j--;
        }

        return (max_num == 0) ? -1 : max_num;
    }
};