#include "header.hpp"
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(const auto& a:arr){
            if(a%2==1){
                count++;
                if(count==3){
                    return true;
                }
            }else{
                count = 0;
            }
        }
        return false;
    }
};