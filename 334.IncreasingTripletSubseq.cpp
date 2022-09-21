#include "header.hpp"
class Solution
{
public:
    bool increasingTripletBF(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        // dp[i] means, count( < nums[:i] )
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // if there is a number less than current number
                if (nums[j] < nums[i])
                {
                    // dp[i] must be greater than any dp[j]
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] >= 3)
                        return true;
                }
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        // m1 is the local minimum
        // once m2 is updated, there will be at least one number smaller than m2
        // if there is a number bigger than m2, then there will be a triplet
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (const auto &num : nums)
        {
            if (m1 >= num)
                m1 = num;
            else if (m2 >= num)
                m2 = num;
            // if m2 isn't updated, else is never gonna happen
            else
                return true;
        }

        return false;
    }

    bool increasingTriplet2(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        // m1 is the local minimum
        // once m2 is updated, there will be at least one number smaller than m2
        // if there is a number bigger than m2, then there will be a triplet
        int m1 = INT_MAX;
        int m2 = INT_MAX;

        for (const auto &num : nums)
        {
            // update m1
            if (num < m1)
            {
                m1 = num;
                continue;
            }
            // m2 is the second smallest number
            if (num < m2 && num > m1)
            {
                m2 = num;
                continue;
            }

            if (num > m2)
                return true;
        }

        return false;
    }
};
//[2,1,5,0,4,6]
// m1=0, m2 = 5,