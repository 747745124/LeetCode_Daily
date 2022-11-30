#include "header.hpp"
class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        vector<int> dp_red(n, INT32_MAX);
        vector<int> dp_blue(n, INT32_MAX);
        vector<int> dp_green(n, INT32_MAX);

        dp_red[0] = costs[0][0];
        dp_blue[0] = costs[0][1];
        dp_green[0] = costs[0][2];

        for (int i = 0; i < (costs.size() - 1); i++)
        {
            // on day i,
            dp_red[i + 1] = min(dp_blue[i] + costs[i + 1][0], dp_green[i] + costs[i + 1][0]);
            dp_blue[i + 1] = min(dp_red[i] + costs[i + 1][1], dp_green[i] + costs[i + 1][1]);
            dp_green[i + 1] = min(dp_red[i] + costs[i + 1][2], dp_blue[i] + costs[i + 1][2]);
        }

        vector<int> res = {dp_red.back(), dp_blue.back(), dp_green.back()};
        return *min_element(res.begin(), res.end());
    }
};