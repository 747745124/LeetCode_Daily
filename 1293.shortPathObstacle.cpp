#include "header.hpp"
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        //dp[i][j][k] is the shortest path from (0,0) to (i,j) with k obstacles removed
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k + 1, INT32_MAX)));

        //steps from top left to bottom right
        dp[m-1][n-1][k] = 0;

        solve(grid, dp, 0, 0, k);

        return dp[0][0][k] == INT32_MAX ? -1 : dp[0][0][k];
    }

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    void solve(vector<vector<int>>&grid, vector<vector<vector<int>>>& dp, int i, int j, int k) {
        if(!isValid(i, j, grid)) return;

        if(dp[i][j][k] != INT32_MAX) return;

        if(grid[i][j] == 1) {
            if(k > 0) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k-1] + 1);
            }
            else {
                dp[i][j][k] = INT32_MAX;
            }
        }
        else {
            dp[i][j][k] = min(dp[i][j][k], dp[i+1][j][k] + 1);
            dp[i][j][k] = min(dp[i][j][k], dp[i][j+1][k] + 1);
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + 1);
            dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k] + 1);
        }

        solve(grid, dp, i+1, j, k);
        solve(grid, dp, i, j+1, k);
        solve(grid, dp, i-1, j, k);
        solve(grid, dp, i, j-1, k);
    }


};