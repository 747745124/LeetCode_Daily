#include "header.hpp"
class Solution
{
public:
    long long minimumHealth(vector<int> &damage, int armor)
    {
        return std::accumulate(damage.begin(), damage.end(), 0LL) - min(armor, *max_element(damage.begin(), damage.end())) + 1;
    }
};