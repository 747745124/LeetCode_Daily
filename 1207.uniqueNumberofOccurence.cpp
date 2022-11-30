#include "header.hpp"
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> num_occurrences;
        unordered_set<int> occurrences;
        for (const auto &num : arr)
        {
            num_occurrences[num]++;
        }

        for (const auto &kv : num_occurrences)
        {
            if (!occurrences.count(kv.second))
                occurrences.insert(kv.second);
            else
                return false;
        }

        return true;
    }
};