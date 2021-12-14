#include "header.hpp"
// in its essence, the minimum number of odds and evens
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        unsigned long even = 0;
        for (const auto &i : position)
            if (i % 2)
                even++;

        return min(position.size() - even, even);
    }
};
