#include "header.hpp"
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n, -1));
        queue<vector<int>> dests;
        dests.push(entrance);
        vector<int> dirs = {-1, 0, 1, 0, -1};
        isVisited[entrance[0]][entrance[1]] = 0;

        while (!dests.empty())
        {
            auto &dest = dests.front();
            int x = dest[0];
            int y = dest[1];
            dests.pop();
            // if it is the exit
            if (maze[x][y] != '+' && (x == 0 || y == 0 || x == (m - 1) || y == (n - 1)))
            {
                if (!(x == entrance[0] && y == entrance[1]))
                {
                    return isVisited[x][y];
                }
            }
            // otherwise, push all its adjacent entries
            for (int i = 0; i < 4; i++)
            {
                int dx = dirs[i];
                int dy = dirs[i + 1];
                // out of border
                if ((x + dx < 0) || (y + dy < 0) || (x + dx >= m) || (y + dy >= n))
                    continue;
                // wall or visited
                if (maze[x + dx][y + dy] == '+' || isVisited[x + dx][y + dy] != -1)
                    continue;
                isVisited[x + dx][y + dy] = isVisited[x][y] + 1;
                dests.push({x + dx, y + dy});
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    cout << s.nearestExit(maze, entrance) << endl;
    return 0;
}