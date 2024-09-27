#include "header.hpp"

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        //represent the number of valid strings we can form with the first i characters of target
        vector<int> dp(target.size()+1,INT16_MAX);
        set<string> prefixSet;

        for(auto word : words){
            for(int i = 0; i < word.size(); i++){
                prefixSet.insert(word.substr(0,i+1));
            }
        }

        int n = target.size();
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(prefixSet.count(target.substr(j,i-j))){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};