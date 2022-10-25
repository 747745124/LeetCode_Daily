#include "header.hpp"
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = ((1 + n) * n) / 2;

        int actual = accumulate(nums.begin(), nums.end(), 0);

        int diff = sum - actual;

        return {
            n - diff - 1, n - diff};
    }
};