#include "header.hpp"
// this works only if majority (>0.5) exists
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj = nums[0];
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                maj = nums[i];

            if (nums[i] == maj)
                count++;
            else
                count--;
        }
        // unordered_map<int, int> presences;
        // int border = nums.size() / 2;
        // for (const auto &num : nums)
        // {
        //     presences[num] += 1;
        //     if (presences[num] > border)
        //         return num;
        // }
    }
};