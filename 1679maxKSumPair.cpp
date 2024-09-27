#include "header.hpp"
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int u = nums.size()-1;
        int res = 0;

        while(l<u){
            
            int n1 = nums[l];
            int n2 = nums[u];

            if((n1+n2)==k){
                l++;
                u--;
                res++;
                continue;
            }

            if(n1<(k-n2))
            l++;
            if(n1>(k-n2))
            u--;

        }

        return res;
    }
};