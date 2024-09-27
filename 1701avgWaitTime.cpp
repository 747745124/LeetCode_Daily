#include "header.hpp"
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res = 0.0;
        int curr = 0;

        for(const auto& c:customers){
            
            const auto arrival = c[0];
            const auto time_take = c[1];

            if(curr < arrival){
                //no extra wait time needed;
                res += time_take;
                curr = time_take + arrival;
            }
            else{
                res += (curr + time_take - arrival);
                curr += time_take;
            }

        }

        return res/customers.size();
    }
};