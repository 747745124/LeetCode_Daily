#include "header.hpp"
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minDiff = INT32_MAX;
        int n = nums.size();
        if(n<=4)
            return 0;

        //suppose same or less than 4 values, then diff is 0

        //4 cases, delete the largest 3 max / min
        //delete 2 and 1, largest / smallest or vice versa

        
       int case_1 = nums.back()-nums[3];
       int case_2 = nums[n-4] - nums[0];
       int case_3 = nums[n-2] - nums[2];
       int case_4 = nums[n-3] - nums[1];

       return min({case_1, case_2, case_3, case_4, minDiff});
    }
};