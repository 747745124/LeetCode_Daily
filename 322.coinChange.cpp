#include "header.hpp"
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // unordered_map<int, int> dp;
        queue<pair<int, int>> q;
        int min_res = INT32_MAX;
        q.push(make_pair(amount, 0));
        while (!q.empty())
        {
            // pair: residual, coins number
            auto node = q.front();
            q.pop();
            if (node.first == 0)
            {
                min_res = min(min_res, node.second);
            }

            for (const auto &coin : coins)
            { // pruning
                if ((node.first - coin) < 0)
                    continue;
                q.push(make_pair(node.first - coin, node.second + 1));
            }
        }

        return min_res == INT32_MAX ? -1 : min_res;
    }
};

int main()
{
    vector<int> coins = {186, 419, 83, 408};
    Solution solution;
    cout << solution.coinChange(coins, 6249);
}