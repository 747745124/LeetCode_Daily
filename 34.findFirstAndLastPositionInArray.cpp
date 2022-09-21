#include "header.hpp"
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v{-1, -1};
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (!binary_search(nums.begin(), nums.end(), target))
            return v;
        v[0] = low, v[1] = high - 1;
        return v;
    }
};