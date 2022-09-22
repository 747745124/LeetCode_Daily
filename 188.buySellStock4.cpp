#include "header.hpp"
class Solution
{
public:
    int helper(vector<int> &prices, vector<vector<vector<int>>> &dp, bool bought, int transactions, int k, int day)
    {
        if (transactions == 0 || day >= prices.size())
            return 0;
        if (dp[bought][transactions][day] != -1)
            return dp[bought][transactions][day];

        int res = helper(prices, dp, bought, transactions, k, day + 1);
        if (bought)
            res = max(res, helper(prices, dp, false, transactions - 1, k, day + 1) + prices[day]);
        else
            res = max(res, helper(prices, dp, true, transactions, k, day + 1) - prices[day]);

        dp[bought][transactions][day] = res;

        return res;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(prices.size(), -1)));
        return helper(prices, dp, false, k, k, 0);
    }
};

int main()
{
    Solution s;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << s.maxProfit(2, prices) << endl;
    return 0;
}