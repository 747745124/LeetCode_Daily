#include "header.hpp"
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> sumOccur;
        sumOccur[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        { // check how many prefix sum equals sum-k;
            sum = sum + nums[i];
            if (sumOccur[sum - k] != 0)
                count += sumOccur[sum - k];
            sumOccur[sum]++;
        }

        return count;
    }
};