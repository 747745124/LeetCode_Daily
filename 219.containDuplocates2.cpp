#include "header.hpp"
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> first_position;

        for (int i = 0; i < nums.size(); i++)
        {
            if (first_position.count(nums[i]) != 0)
            {
                if (i - first_position[nums[i]] <= k)
                    return true;
            }
            first_position[nums[i]] = i;
        }

        return false;
    }
};