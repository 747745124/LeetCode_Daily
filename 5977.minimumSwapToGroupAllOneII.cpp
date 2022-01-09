#include "header.hpp"
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        // circular sliding window
        // check how many 1's in the array
        int windowSize = 0;
        int currZero = 0;
        for (const auto &i : nums)
        {
            windowSize += i;
        }

        for (int i = 0; i < windowSize; i++)
        {
            if (nums[i] == 0)
            {
                currZero++;
            }
        }

        int res = currZero;
        for (int i = windowSize; i < nums.size() + windowSize; i++)
        {
            if (nums[i % nums.size()] == 0)
                currZero += 1;
            if (nums[i - windowSize] == 0)
                currZero -= 1;

            res = min(res, (currZero));
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << solution.minSwaps(nums) << endl;
    return 0;
}