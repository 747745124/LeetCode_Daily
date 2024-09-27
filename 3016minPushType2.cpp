#include "header.hpp"
class Solution {
public:
    int minimumPushes(string word) {
        //freq map
        unordered_map<char, int> freq;
        for (char c : word)
        {
            freq[c]++;
        }

        //vector of freq, ordered by freq
        vector<int> freqs;
        for (auto &p : freq)
        {
            freqs.push_back(p.second);
        }

        //sort freqs, descending
        sort(freqs.begin(), freqs.end(), greater<int>());
        
        int res = 0;
        for(int i = 0; i < freqs.size(); i++)
        {
            res += freqs[i] * ceil((i+1)/8.f);
        }

        return res;
    }
};