#include "header.hpp"
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        multimap<int, int, std::greater<int>> frequencies;
        for (const auto &ch : s)
        {
            freq[ch]++;
        }

        for (auto &kv : freq)
        {
            frequencies.insert(make_pair(kv.second, kv.first));
        }

        string res = "";
        for (auto &kv : frequencies)
        {
            for (int i = 0; i < kv.first; i++)
            {
                res += (kv.second);
            }
        }

        return res;
    }
};