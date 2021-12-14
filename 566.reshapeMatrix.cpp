#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //if valid, output the reshaped solution
    //otherwise, output original solution
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c)
    {
        //invalid
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;

        //flatten
        vector<int> flatten(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                flatten[i * n + j] = mat[i][j];
        }

        //valid solution
        vector<vector<int> > res(r);
        for (int i = 0; i < r; i++)
        {
            vector<int> row(c);
            for (int j = 0; j < c; j++)
                row[j] = flatten[i * c + j];

            res[i] = row;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.matrixReshape() << endl;
}