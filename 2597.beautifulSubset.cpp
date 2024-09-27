#include "header.hpp"
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;

        return countBeautifulSubsets(nums,k,freq,0);


    }

    int countBeautifulSubsets(vector<int>& nums,int diff, unordered_map<int, int>& freq,int index) {
 // Base case: Return 1 for a subset of size 1
        if (index == nums.size()) {
            return 1;
        }
        // Count subsets where nums[i] is not taken
        int totalCount = countBeautifulSubsets(nums, diff, freq,
                                               index + 1); // nums[i] not taken

        // If nums[i] can be taken without violating the condition
        if (!freq[nums[i] - diff]) {
            freq[nums[i]]++;
            // Recursively count subsets where nums[i] is taken
            totalCount += countBeautifulSubsets(nums, diff, freq,
                                                i + 1); // nums[i] taken
            freq[nums[i]]--;
        }

        return totalCount;
    }
};