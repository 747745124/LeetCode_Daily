#include "header.hpp"
class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (col >= 0 && row < matrix.size())
        {
            int num = matrix[row][col];
            if (num == target)
                return true;

            if (num > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    cout << solution.searchMatrix(matrix, 18) << endl;
}