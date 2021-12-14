#include "header.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> hold(n + 1);
        vector<int> sell(n + 1);
        vector<int> rest(n + 1);

        hold[0] = INT32_MIN;
        sell[0] = 0;
        rest[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            sell[i] = hold[i - 1] + prices[i - 1];
            hold[i] = max(hold[i - 1], rest[i - 1] - prices[i - 1]);
            rest[i] = max(rest[i - 1], sell[i - 1]);
        }

        return max(sell[n], rest[n]);
    }
};

int main()
{
    Solution s;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << s.maxProfit(prices) << endl;
    return 0;
}