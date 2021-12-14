#include "header.hpp"
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        for (int i = 1; i < board.size() - 1; i++)
        {
            for (int j = 1; j < board[0].size() - 1; j++)
            {
                if (board[i][j] == 'X')
                    continue;
                if (!isConnected(board, i, j))
                    board[i][j] = 'X';
            }
        }
    }

private:
    //if an O is connected to an O on the boarder
    bool isConnected(vector<vector<char>> &board, int i, int j)
    {
        if (i >= board.size() || i < 0)
            return true;
        if (j >= board[0].size() || j < 0)
            return true;

        if (board[i][j] == 'X')
            return false;

        if (board[i][j] == 'K')
            return false;

        char tmp = board[i][j];
        board[i][j] = 'K';
        bool result = isConnected(board, i + 1, j) || isConnected(board, i - 1, j) || isConnected(board, i, j - 1) || isConnected(board, i, j + 1);
        board[i][j] = tmp;

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
    };

    s.solve(board);
    for (auto i : board)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}