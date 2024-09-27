#include "header.hpp"
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<uint64_t> prefixSum(n,0);
        prefixSum[0] = chalk[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = chalk[i] + prefixSum[i-1];
        }

        if(chalk.back() < k)
            k = k%((int)chalk.back());
        
        auto it = std::find_if(prefixSum.begin(), prefixSum.end(),[&](uint64_t num){
            k < num;
        });

        return *it;
    }
};