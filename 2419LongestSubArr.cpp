#include "header.hpp"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {


        int res = 0;
        int currRes = 0;
        auto max_pos = max_element(nums.begin(), nums.end());
        int max_elem = *max_pos;

        while(max_pos != nums.end()){
            if(*max_pos == max_elem)
            {
                currRes++;
                res++;
                max_pos+=1;
            }
            else{
                res = max(currRes, res);
                currRes = 0;
                max_pos++;
            }
        }

        return res;
        
    }
};