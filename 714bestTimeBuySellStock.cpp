#include "header.hpp"
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //each day, buy or sell or do nothing
        int result = 0;
        int n = prices.size();
        //dp[i][j] maxprofit on day i, with status j (having stock or not)
        vector<vector<int>> dp(n,vector<int>(2,0));
        //day 0 with having stock status.
        dp[0][1] = -prices[0];

        for(int i = 1; i < n; i++){
            int price = prices[i];

            //on day i with having stock status, either not selling it or buying it
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] - fee);

        }

        return max(dp[n-1][0],dp[n-1][1]);

    }
};