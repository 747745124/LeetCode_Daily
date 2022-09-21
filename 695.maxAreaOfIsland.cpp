#include "header.hpp"
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // mapping 2d positions to 1d num for disjoint set
        vector<std::pair<int, int>> all_ones;
        vector<vector<int>> dirs = {{-1, 0},
                                    {0, -1},
                                    {0, 1},
                                    {1, 0}};

        map<std::pair<int, int>, int>
            mapping_dict;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    all_ones.push_back(std::make_pair(i, j));
                }
            }
        }

        DisjointSet disSet(all_ones.size());
        for (int i = 0; i < all_ones.size(); i++)
        {
            mapping_dict[all_ones[i]] = i;
        }

        for (const auto &position : all_ones)
        {
            for (const auto &dir : dirs)
            {
                int x = position.first + dir[0];
                int y = position.second + dir[1];
                if (find(all_ones.begin(), all_ones.end(), std::make_pair(x, y)) != all_ones.end())
                {
                    disSet.setUnion(mapping_dict[position], mapping_dict[std::make_pair(x, y)]);
                }
            }
        }

        int res = 0;
        vector<int> groups(50, 0);
        for (int i = 0; i < disSet.set.size(); i++)
        {
            int head = disSet.find(mapping_dict[all_ones[i]]);
            groups[head]++;
        }

        for (const auto &elem : groups)
        {
            if (elem != 0)
                res = max(res, elem);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << solution.maxAreaOfIsland(grid);
    return 0;
}