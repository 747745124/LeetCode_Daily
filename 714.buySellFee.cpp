#include "header.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> bought; // max profit on day i with stock in hold
        vector<int> sold;   // max profit on day i with no stock in hold
        bought[0] = -prices[0] - fee;
        sold[0] = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            bought[i] = max(bought[i - 1], sold[i - 1] - prices[i] - fee);
            sold[i] = max(bought[i - 1] + prices[i], sold[i - 1]);
        }

        return max(sold[n - 1], sold[n - 1]);
    }
};