#include "header.hpp"
class Solution
{
public:
    int minScore(int n, vector<vector<int>> roads)
    {
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
        vector<vector<int>> map(n, vector<int>(n, INT32_MAX));

        // for (int i =  0; i < n; i++)
        // {
        //     dp[i][i] = 0;
        // }

        for (auto &road : roads)
        {

            map[road[0] - 1][road[1] - 1] = road[2];
            map[road[1] - 1][road[0] - 1] = road[2];
            dp[road[0] - 1][road[0] - 1] = min(dp[road[0] - 1][road[0] - 1], road[2]);
            dp[road[1] - 1][road[1] - 1] = min(dp[road[1] - 1][road[1] - 1], road[2]);
        }

        return shortDistance(0, n - 1, dp, map);

        // int res = INT32_MAX;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         res = min(res, dp[i][j]);
        // }
    }

    int shortDistance(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &map)
    {
        if (dp[i][j] != INT32_MAX)
            return dp[i][j];

        int res = INT32_MAX;
        for (int k = 0; k < dp.size(); k++)
        {
            if (i == k || j == k || i == j)
                continue;
            if ((map[i][k] == INT32_MAX) || (map[k][j] == INT32_MAX))
                continue;

            res = min(shortDistance(i, k, dp, map), shortDistance(j, k, dp, map));
        }

        return dp[i][j] = res;
    }
};

int main()
{
    Solution solution;
    cout << solution.minScore(4, {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}}) << endl;
}