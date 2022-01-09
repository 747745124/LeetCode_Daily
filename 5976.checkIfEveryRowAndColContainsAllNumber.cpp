#include "header.hpp"
class Solution
{
public:
    bool checkValid(vector<vector<int>> matrix)
    {
        int size = matrix.size();

        for (auto &row : matrix)
        {
            unordered_map<int, int> presence;
            for (auto &elem : row)
            {
                if (presence[elem] != 0)
                    return false;
                presence[elem]++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            unordered_map<int, int> presence;
            for (int j = 0; j < size; j++)
            {
                auto elem = matrix[j][i];
                if (presence[elem] != 0)
                    return false;
                presence[elem]++;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.checkValid({{1, 2, 3}, {3, 1, 2}, {2, 3, 1}}) << endl;
}