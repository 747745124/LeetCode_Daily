#include "header.hpp"
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int getSum = std::accumulate(nums.begin(), nums.end(), 0);
        // if odd, imporrisble for 2 partition
        if (getSum % 2)
            return false;
        // record
        vector<vector<bool>> dp(nums.size(), vector<bool>(getSum / 2, false));
        return dfs(nums, 0, 0, getSum / 2, dp);
    }

    bool dfs(vector<int> &nums, int i, int currSum, int targetSum, vector<vector<bool>> &dp)
    {
        if (i >= nums.size())
        {
            dp[i][currSum] = false;
            return false;
        }
        if (currSum == targetSum)
        {
            dp[i][currSum] = true;
            return true;
        }
        if (currSum > targetSum)
        {
            dp[i][currSum] = false;
            return false;
        }

        if (dp[i][currSum] != false)
            return dp[i][currSum];

        if (dfs(nums, i + 1, currSum + nums[i], targetSum, dp) || dfs(nums, i + 1, currSum, targetSum, dp))
        {
            return true;
        }

        return false;
    }
};