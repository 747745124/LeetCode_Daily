#include "header.hpp"
class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        for (const auto &word : words)
        {
            if (exist(board, word))
            {
                res.push_back(word);
            }
        }
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        if (n == 0)
            return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
    //search word from board[i][j], check if it's the same as the word[k]
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] != word[k])
            return false;
        char tmp = board[i][j];
        board[i][j] = '#';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);

        board[i][j] = tmp;
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> res = s.findWords(board, words);
    for (const auto &str : res)
    {
        cout << str << endl;
    }
    return 0;
}