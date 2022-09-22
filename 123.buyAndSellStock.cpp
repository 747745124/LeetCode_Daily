#include "header.hpp"
class Solution
{
public:
    int helper(vector<int> &prices, vector<vector<vector<int>>> &dp, bool buy, int transactions, int day)
    {
        if (transactions == 0 || day >= prices.size())
            return 0;

        if (dp[buy][transactions][day] != -1)
            return dp[buy][transactions][day];

        // each day, buy or sell or keep
        // buy or sell指的是上一天的状态
        int res = helper(prices, dp, buy, transactions, day + 1); // skip
        if (buy)
            res = max(res, prices[day] + helper(prices, dp, false, transactions + 1, day + 1)); // sell
        else
            res = max(res, -prices[day] + helper(prices, dp, true, transactions, day + 1)); // buy

        dp[buy][transactions][day] = res;
        return res;
    };

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(n, -1)));
        // state: state, #transactions done，which date

        int res = helper(prices, dp, false, 0, 0);
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}