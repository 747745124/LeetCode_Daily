#include "header.hpp"
class Solution
{
public:
    int islandPerimeter(vector<vector<int> > &grid)
    {
        int res = 0;
        //the perimeter equals to 4*n-2*adjacency
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 0)
                    continue;

                res += 4;

                if (i >= 1 && grid[i - 1][j] == 1)
                    res -= 1;
                if (i < grid.size() - 1 && grid[i + 1][j] == 1)
                    res -= 1;
                if (j >= 1 && grid[i][j - 1] == 1)
                    res -= 1;
                if (j < grid[0].size() - 1 && grid[i][j + 1] == 1)
                    res -= 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > grid{{0, 1}};
    cout << solution.islandPerimeter(grid);
    return 0;
}