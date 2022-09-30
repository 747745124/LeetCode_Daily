#include "header.hpp"
class Solution
{
public:
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int n = matrix.size();
        int m = matrix[0].size();
        int dirs[] = {0, -1, 0, 1, 0};
        dp[i][j] = 1; // visited, also the minimum number
        for (int i = 0; i < 4; i++)
        {
            int i_new = i + dirs[i];
            int j_new = j + dirs[i + 1];
            if (i_new < 0 || i_new >= n || j_new < 0 || j_new >= m || matrix[i_new][j_new] <= dp[i][j])
                continue;

            dp[i][j] = max(dp[i][j], 1 + helper(matrix, dp, i_new, j_new));
        }

        return dp[i][j];
    };

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
            {
                res = max(res, helper(matrix, dp, i, j));
            }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    s.longestIncreasingPath(matrix);
}