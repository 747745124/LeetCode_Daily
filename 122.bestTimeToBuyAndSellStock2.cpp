#include "header.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //finite state
        //hold, the maximum total profit, till day i
        //sold, the maximum total profit, till day i
        int n = prices.size();
        vector<int> hold(n + 1), sold(n + 1);
        hold[0] = INT32_MIN;
        sold[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            sold[i] = hold[i - 1] + prices[i - 1];
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i - 1]);
        }
        int res = max(hold.back(), sold.back());
        if (res > 0)
            return res;
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);
    return 0;
}