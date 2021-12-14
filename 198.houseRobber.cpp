#include "header.hpp"
class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(dp[0], dp[1]);

        if (n < 2)
            return nums[0];
        //dp(n) stores the maximum number after visit house(n);
        //one can either skip this (don't stole), or stole(but not stole in the next round)
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};
int main()
{
    Solution solution;
    vector<int> m{1, 2};
    cout << solution.rob(m);
}