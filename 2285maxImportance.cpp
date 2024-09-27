#include "header.hpp"
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //sort by degrees
        vector<int> freq(n, 0);
        for(const auto& road:roads){
            freq[road[0]]++;
            freq[road[1]]++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int result = 0;
        for(const auto& f:freq){
            result += f*(n-1);
            n--;
        }

        return result;
    }
};

