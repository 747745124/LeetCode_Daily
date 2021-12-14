#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int> > res;
    vector<int> a;
    //initialize a n*n matrix
    for (int i = 0; i < 3; i++)
    {
        vector<int> row;
        for (int j = 1; j < 5; j++)
        {
            row.push_back(j + 4 * i);
        }
        res.push_back(row);
    }

    int m = res.size();
    int n = res[0].size();

    for (int layer = 0; layer < (min(m, n) + 1) / 2; layer++)
    {
        //for each layer we do 4 directions
        //left to right
        for (int i = layer; i < n - layer; i++)
        {
            a.push_back(res[layer][i]);
        }
        //up to down
        for (int i = layer + 1; i < m - layer; i++)
        {
            a.push_back(res[i][n - layer - 1]);
        }
        if (a.size() != m * n)
        {
            //right to left
            for (int i = n - layer - 2; i >= layer; i--)
            {
                a.push_back(res[m - layer - 1][i]);
            }
            //down to up
            for (int i = m - layer - 2; i > layer; i--)
            {
                a.push_back(res[i][layer]);
            }
        }
    }
    //print a
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}