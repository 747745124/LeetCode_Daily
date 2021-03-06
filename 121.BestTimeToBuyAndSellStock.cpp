#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int n = prices.size();
        if (n < 1)
            return 0;

        int min_price = prices[0];
        int max_profits = 0;

        // vector<int> min_prices(n);
        // vector<int> max_profit(n);

        // min_prices[0] = prices[0];
        // max_profit[0] = 0;

        // for (int i = 1; i < n; i++)
        // {
        //     min_prices[i] = min(min_prices[i - 1], prices[i]);
        //     max_profit[i] = max(max_profit[i - 1], prices[i] - min_prices[i]);
        // }

        for (int i = 1; i < n; i++)
        {
            min_price = min(min_price, prices[i]);
            max_profits = max(max_profits, prices[i] - min_price);
        }

        return max_profits;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices);
}