#include "header.hpp"
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        if (word.size() > m * n)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (word[0] == board[i][j])
                    if (dfs(board, i, j, 0, word))
                        return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int k, string word)
    {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool res = dfs(board, i + 1, j, k + 1, word) || dfs(board, i, j + 1, k + 1, word) || dfs(board, i, j - 1, k + 1, word) || dfs(board, i - 1, j, k + 1, word);
        board[i][j] = temp;
        return res;
    }
};
