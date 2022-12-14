#include "header.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> bought(n, 0);
        vector<int> sold(n, 0);
        vector<int> cd(n, 0);

        bought[0] = -prices[0];
        sold[0] = 0;
        cd[0] = 0;

        for (int i = 1; i < n; i++)
        {
            bought[i] = max({cd[i - 1] - prices[i], bought[i - 1]});
            sold[i] = max({bought[i - 1] + prices[i], cd[i - 1]});
            cd[i] = max({cd[i - 1], sold[i - 1]});
        }

        return max(sold[n - 1], cd[n - 1]);
    }
};