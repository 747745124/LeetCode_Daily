#include "header.hpp"
class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        transpose(matrix);
        reflect(matrix);
    }

private:
    void transpose(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        //only do this to upper left of the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // this is actually reflect by y axis, only take effect on left side
    void reflect(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][n - 1 - j], matrix[i][j]);
            }
        }
    }
};