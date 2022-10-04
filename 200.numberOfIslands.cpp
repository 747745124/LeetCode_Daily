#include "header.hpp"
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // using dfs
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(grid, visited, i, j))
                    res++;
            }
        }

        return res;
    }

    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;

        if (visited[i][j] == true)
            return false;

        if (grid[i][j] == '0')
        {
            visited[i][j] = true;
            return false;
        }

        if (grid[i][j] == '1' && visited[i][j] == false) // find someone new, mark all its connections;
        {
            visited[i][j] = true;
            dfs(grid, visited, i + 1, j);
            dfs(grid, visited, i - 1, j);
            dfs(grid, visited, i, j + 1);
            dfs(grid, visited, i, j - 1);
            return true;
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '1', '0', '0'},
                              {'0', '0', '0', '1', '1'}};
    cout << s.numIslands(grid);
}