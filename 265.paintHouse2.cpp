#include "header.hpp"
class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size(), 100));
        for (int i = 0; i < costs[0].size(); i++)
        {
            dp[0][i] = costs[0][i];
        }

        for (int i = 0; i < costs.size() - 1; i++)
        {
            // each day
            for (int j = 0; j < costs[0].size(); j++)
            {
                // find max among dp[i-1][k],where k!=j
                int min_val = INT16_MAX;
                for (int k = 0; k < costs[0].size(); k++)
                {
                    if (k == j)
                        continue;
                    min_val = min(min_val, dp[i][k]);
                }

                dp[i + 1][j] = min_val + costs[i + 1][j];
            }
        }

        int res = INT16_MAX;
        for (int i = 0; i < costs[0].size(); i++)
        {
            res = min(res, dp[costs.size() - 1][i]);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> costs = {{1, 5, 3}, {2, 9, 4}};
    cout << s.minCostII(costs) << endl;
    return 0;
}