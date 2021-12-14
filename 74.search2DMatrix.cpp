#include "header.hpp"
class Solution
{
    /*
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    */
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        for (const auto &row : matrix)
        {
            if (row.back() < target)
                continue;
            return binary_search(row.begin(), row.end(), target);
        }
        return false;
    }
};
