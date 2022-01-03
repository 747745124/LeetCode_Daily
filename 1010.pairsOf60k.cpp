#include "header.hpp"
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < time.size(); i++)
        {
            int t = time[i];
            int x = t % 60;
            int y = (60 - x) % 60;
            ans += m[y];
            m[x]++;
        }
        return ans;
    }
};