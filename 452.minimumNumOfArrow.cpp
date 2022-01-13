#include "header.hpp"
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // sort by the first element
        sort(points.begin(), points.end());
        int res = points.size();
        vector<vector<int>> temp;
        temp.push_back(points[0]);
        for (int i = 1; i < points.size(); i++)
        {
            // if disjoint, push back
            if (temp.back()[1] < points[i][0])
            {
                temp.push_back(points[i]);
                continue;
            }

            // if not disjoint, get intersection
            // start point
            temp.back()[0] = points[i][0];
            // end point
            temp.back()[1] = min(temp.back()[1], points[i][1]);
            res--;
        }

        return res;
    };
};
int main()
{
    Solution s;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}