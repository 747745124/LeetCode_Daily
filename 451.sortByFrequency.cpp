#include "header.hpp"
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        vector<pair<char, int>> a;
        string str = "";

        for (const auto &ch : s)
        {
            freq[ch]++;
        }

        for (const auto &kv : freq)
        {
            a.push_back(kv);
        }

        sort(a.begin(), a.end(), [](pair<char, int> &a, pair<char, int> &b)
             { return a.second > b.second; });

        for (const auto &kv : a)
        {
            for (int i = 0; i < kv.second; i++)
                str += kv.first;
        }
        return str;
    };
};