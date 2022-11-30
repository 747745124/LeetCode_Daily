#include "header.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int current_low = INT32_MAX;
        int max_profit = 0;
        for (auto &price : prices)
        {
            current_low = min(current_low, price);
            max_profit = max(max_profit, price - current_low);
        }
        return max_profit;
    }
};