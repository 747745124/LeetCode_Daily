#include "header.hpp"
class Solution
{
public:
    unordered_map<int, u_int64_t> m;
    uint64_t fact(int n)
    {

        return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
    }

    void prepareMap(unordered_map<int, u_int64_t> &m, int maxTime)
    {
        for (int i = 0; i <= maxTime; i++)
        {
            m[i] = fact(i);
        }
    }

    vector<vector<int> > generate(int numRows)
    {
        // prepareMap(m, numRows);
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; i++)
            res[i] = genRow(i);
        return res;
    }

    vector<int> genRow(int n)
    {
        vector<int> res(n + 1);
        res[0] = 1;
        //C(n, i+1) = C(n, i) * (n-i) / (i+1)
        for (int i = 0; i < n; i++)
            res[i + 1] = res[i] * ((n - i) / (i + 1));
        return res;
    }
};