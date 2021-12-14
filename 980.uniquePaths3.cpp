#include "header.hpp"
//walks over every grid exactly once
class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        pair<int, int> start;
        int walkable = 1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    start = make_pair(i, j);
                if (grid[i][j] == 0)
                    walkable++;
            }
        }
        return dfs(grid, start.first, start.second, walkable);
    }

private:
    int dfs(vector<vector<int>> &grid, int x, int y, int walkable)
    {
        //end case: either out of range or not walkable
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
            return 0;
        //end case:go to the end,
        if (grid[x][y] == 2)
            return walkable == 0;

        grid[x][y] = -1;
        int result = dfs(grid, x - 1, y, walkable - 1) + dfs(grid, x + 1, y, walkable - 1) + dfs(grid, x, y - 1, walkable - 1) + dfs(grid, x, y + 1, walkable - 1);
        grid[x][y] = 0;

        return result;
    };
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << s.uniquePathsIII(grid) << endl;
    return 0;
}