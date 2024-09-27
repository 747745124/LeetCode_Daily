#include "header.hpp"
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[&](vector<int>&a,vector<int>&b) {
            if(a[0]!=b[0])
                return a[0] < b[0];
            return a[1]<b[1];
        });

        vector<vector<int>> ivs;
        ivs.push_back(intervals[0]);
        int merge_count = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(ivs.back()[1]<=intervals[i][0])
            {
                ivs.push_back(intervals[i]);
                continue;
            }

            ivs.back()[1] = min(ivs.back()[1], intervals[i][1]);
            merge_count++;
        }

        return merge_count;
    }
};