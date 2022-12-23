#include "header.hpp"

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int maxScore = INT32_MIN;
        int maxVal = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            maxScore = max(maxScore, maxVal + values[i] - i);
            maxVal = max(maxVal, values[i] + i);
        }
        return maxScore;
    }
};