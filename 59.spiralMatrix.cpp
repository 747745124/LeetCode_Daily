#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > res;
    //initialize a n*n matrix
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back(0);
        }
        res.push_back(row);
    }
    //generate the spiral matrix
    //we have n+1/2 layers to traverse
    int cnt = 0;
    for (int layer = 0; layer < (n + 1) / 2; layer++)
    {
        //for each layer we do 4 directions
        //left to right
        for (int i = layer; i < n - layer; i++)
        {
            res[layer][i] = ++cnt;
        }
        //up to down
        for (int i = layer + 1; i < n - layer; i++)
        {
            res[i][n - layer - 1] = ++cnt;
        }
        //right to left
        for (int i = n - layer - 2; i >= layer; i--)
        {
            res[n - layer - 1][i] = ++cnt;
        }
        //down to up
        for (int i = n - layer - 2; i > layer; i--)
        {
            res[i][layer] = ++cnt;
        }
    }
    //print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}