#include "header.hpp"
// You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].

// Return the maximum possible length of a good subsequence of nums.
//Input: nums = [1,2,1,1,3], k = 2

// Output: 4

// Explanation:

// The maximum length subsequence is [1,2,1,1,3].
// at most k ordered elements can be different
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        //max length of the subseq that, before index i, exactly j elements are different, last element is at pos k
        vector<vector<vector<int> > > dp(nums.size()+1, vector<vector<int>>(k+1, vector<int>(nums.size()+1, -1)));
        return maxLengthBeforeIndex(dp, nums, 0, k, -1);
    }

    int maxLengthBeforeIndex(vector<vector<vector<int>>>&dp, const vector<int> &nums, int i,int j, int prev_pos){
            if(i == nums.size()) return 0;
            if(dp[i][j][prev_pos+1] != -1) return dp[i][j][prev_pos+1];

            //not take the current element
            int maxLen = maxLengthBeforeIndex(dp, nums, i+1, j, prev_pos);
            
            //take the current element, with 2 cases
            if(prev_pos == -1 || nums[prev_pos] == nums[i]){
                maxLen = max(maxLen, 1+maxLengthBeforeIndex(dp, nums, i+1, j, i));
            }
            else if(j > 0){
                maxLen = max(maxLen, 1+maxLengthBeforeIndex(dp, nums, i+1, j-1, i));
            }

            dp[i][j][prev_pos+1] = maxLen;
            return maxLen;
        };
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,1,3};
    cout << s.maximumLength(nums, 2) << endl;
};