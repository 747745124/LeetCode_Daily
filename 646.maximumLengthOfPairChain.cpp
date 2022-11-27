#include "header.hpp"
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        sort(
            pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
            { return a[1] < b[1]; });

        int res = 0;
        int curr = INT32_MIN;
        for (auto &pair : pairs)
        {
            if (pair[0] > curr)
            {
                res++;
                curr = pair[1];
            }
            else
                continue;
        }

        return res;
    }
};