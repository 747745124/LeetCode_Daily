#include "header.hpp"
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (n == 1 && trust.size() == 0)
            return 1;

        unordered_map<int, int> getVote;
        unordered_map<int, int> getVoter;
        for (const auto &vote : trust)
        {
            getVote[vote[1]]++;
            getVoter[vote[0]]++;
        }

        for (const auto &kv : getVote)
        {
            if (kv.second == (n - 1))
            {
                if (getVoter.count(kv.first))
                    continue;
                else
                    return kv.first;
            }
        }

        return -1;
    }
};