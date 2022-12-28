#include "header.hpp"
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> diffs(capacity.size(), 0);

        for (int i = 0; i < capacity.size(); ++i)
        {
            diffs[i] = capacity[i] - rocks[i];
        }

        sort(diffs.begin(), diffs.end());
        int res = 0;

        for (const auto &diff : diffs)
        {
            additionalRocks -= diff;
            if (additionalRocks <= 0)
                return res;
            res++;
        }
        return res;
    }
};