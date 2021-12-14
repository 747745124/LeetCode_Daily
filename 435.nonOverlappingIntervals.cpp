#include "header.hpp"
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
    {
        //first, sort by the second element
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });
        //we have to get the maximum number of non-overlapping intervals
        //scan from left to right
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            //if overlaps,check next interval
            if (intervals[i][0] < end)
                continue;
            //if not, get new end and count++
            end = intervals[i][1];
            count++;
        }
        return intervals.size() - count;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > intervals{
        {1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals);
}