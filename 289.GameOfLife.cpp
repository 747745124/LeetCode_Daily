#include "header.hpp"
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        /*
        Any live cell with fewer than two live neighbors dies as if caused by under-population.
        Any live cell with two or three live neighbors lives on to the next generation.
        Any live cell with more than three live neighbors dies, as if by over-population.
        Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
        */

        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int count = 0;
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if ((i + k) < 0 || (i + k) >= board.size())
                            continue;
                        if ((j + l) < 0 || (j + l) >= board[0].size())
                            continue;
                        if (board[i + k][j + l] == 1)
                            count++;
                    }
                }

                if (board[i][j] == 1)
                {
                    if (count < 2 || count > 3)
                        res[i][j] = 0;
                    else
                        res[i][j] = 1;
                }
                else
                {
                    if (count == 3)
                        res[i][j] = 1;
                    else
                        res[i][j] = 0;
                }
            }
        }
        board = res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    s.gameOfLife(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}