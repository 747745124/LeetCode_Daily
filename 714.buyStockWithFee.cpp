#include "header.hpp"

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // each day, keep it buy or sell it
        // if bought, keep or sell.

        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0] - fee;
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i] - fee);
        }

        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};