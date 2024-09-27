#include "header.hpp"
class Solution {
    string word_1, word_2;

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        word_1 = word1;
        word_2 = word2;

        return solver(dp,word_1.size(),word_2.size());
    }

    int solver(vector<vector<int>>& dp, int i, int j){
        if(dp[i][j]>=0)
            return dp[i][j];
        
        if(i==0)
            return dp[i][j] = j;

        if(j==0)
            return dp[i][j] = i;
        
        if(word_1[i-1] == word_2[j-1])
            return dp[i][j] = solver(dp,i-1,j-1);
        
        int distance_1 = solver(dp,i-1,j);
        int distance_2 = min(solver(dp,i,j-1),distance_1);
        int distance_3 = min(solver(dp,i-1,j-1)+1,distance_2);

        return dp[i][j] = distance_3;
    };
};