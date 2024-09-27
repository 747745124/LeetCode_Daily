#include "header.hpp"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freqs;
        for(const auto& i : nums2){
            freqs[i]++;
        }

        vector<int> res;

        for(const auto& num : nums1){
            if(freqs.at(num) > 0){
                res.push_back(num);
                freqs[num]--;
            }
        }

        return res;
    }
};