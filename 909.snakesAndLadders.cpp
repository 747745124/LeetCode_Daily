#include "header.hpp"
// 1d jump game, actually
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int res = -1;
        queue<int> q;
        q.push(1);
        bitset<400> isVisited = 0;
        isVisited.set(1);
        int n_square = board.size() * board.size();
        while (q.size() > 0)
        {
            int size_q = q.size();
            for (int i = 0; i < size_q; i++)
            {
                int node = q.front();
                q.pop();

                if (node == n_square)
                    return res + 1;

                for (int j = 1; j <= min(6, n_square - node); j++)
                { // if its a ladder
                    if (isVisited.test(node + j))
                        continue;

                    int val = indexToVal(board, node + j);
                    if (val != -1)
                    {
                        if (isVisited.test(val))
                            continue;
                        q.push(val);
                        isVisited.set(val);
                    }
                    else
                    {
                        q.push(node + j);
                        isVisited.set(node + j);
                    }
                }
            }

            res++;
        }

        return -1;
    }

    int indexToVal(vector<vector<int>> &board, int index)
    {
        int n = board.size();
        int additional_term = ((index % n) == 0) ? 1 : 0;
        int row = index / n - additional_term;
        int col = 0;
        if (row % 2 == 0)
        {
            col = index % n - 1;
            if (col < 0)
                col += n;
        }
        else
        {
            col = n - index % n;
            if (col == n)
                col = 0;
        }

        return board[n - row - 1][col];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> board = {{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
    cout << s.snakesAndLadders(board) << endl;
    return 0;
}