#include "header.hpp"
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {

        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<float, int> slope_freq;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;

                float dy = points[j][1] - points[i][1];
                float dx = points[j][0] - points[i][0];

                slope_freq[dy / dx]++;

                res = max(res, slope_freq[dy / dx]);
            }
        }

        return res + 1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout << solution.maxPoints(points) << endl;
}