#include "header.hpp"
// A simulation solution
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> poured_vec(101, vector<double>(101, 0));
        poured_vec[0][0] = poured;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (poured_vec[i][j] > 1)
                {
                    double overflow = poured_vec[i][j] - 1;
                    // next row  left
                    poured_vec[i + 1][j] += overflow / 2.0;
                    // next row right
                    poured_vec[i + 1][j + 1] += overflow / 2.0;
                    // this element
                    poured_vec[i][j] = 1;
                }
            }
        }

        return poured_vec[query_row][query_glass];
    }
};