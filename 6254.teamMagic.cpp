#include "header.hpp"
class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {

        int sum = std::accumulate(skill.begin(), skill.end(), 0);
        if (!sum % (skill.size() / 2))
            return -1;
        int PairAverage = sum / (skill.size() / 2);

        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        uint64_t res = 0;
        while (i < j)
        {
            if ((skill[i] + skill[j]) != PairAverage)
                return -1;
            res += (skill[i] * skill[j]);
            i++;
            j--;
        }
        return res;
    }
};