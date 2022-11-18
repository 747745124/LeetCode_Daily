#include "header.hpp"
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int intersect_x = 0;
        int intersect_y = 0;
        vector<pair<int, int>> x_intervals = {{ax1, ax2}, {bx1, bx2}};
        sort(x_intervals.begin(), x_intervals.end());
        if (x_intervals[1].first <= x_intervals[0].second && x_intervals[1].first >= x_intervals[0].first)
            intersect_x = min(x_intervals[1].second, x_intervals[0].second) - x_intervals[1].first;
        else
            return area1 + area2;

        vector<pair<int, int>> y_intervals = {{ay1, ay2}, {by1, by2}};
        sort(y_intervals.begin(), y_intervals.end());
        if (y_intervals[1].first <= y_intervals[0].second && y_intervals[1].first >= y_intervals[0].first)
            intersect_y = min(y_intervals[1].second, y_intervals[0].second) - y_intervals[1].first;
        else
            return area1 + area2;

        return area1 + area2 - intersect_y * intersect_x;
    }
};
int main()
{
    Solution solution;
    cout << solution.computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
}