#include "header.hpp"
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> trust)
    {
        vector<int> trust_from(n + 1, 0);
        vector<int> trust_to(n + 1, 0);
        for (auto &t : trust)
        {
            trust_from[t[0]]++;
            trust_to[t[1]]++;
        }
        for (int i = 1; i <= n; i++)
        { // judge trust nobody
            // and every body trust judge
            if (trust_from[i] == 0 && trust_to[i] == n - 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    s.findJudge(4, {{1, 3}, {1, 4}, {4, 3}});
    return 0;
}