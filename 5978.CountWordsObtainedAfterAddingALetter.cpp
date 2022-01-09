#include "header.hpp"
// TLE
class Solution
{
public:
    bool contains(string &a, string &b)
    {
        unordered_map<char, int> presenceA;
        unordered_map<char, int> presenceB;
        for (char ch : a)
            presenceA[ch]++;
        for (char ch : b)
            presenceB[ch]++;

        int count = 0;
        for (const auto &ch : b)
        {
            if (presenceA[ch] == 0)
                count += 1;
            else if (presenceA[ch] != presenceB[ch])
                return false;
            if (count > 1)
                return false;
        }
        return true;
    }

    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_map<int, vector<string>> startLengths;
        unordered_map<int, vector<string>> targetLengths;

        for (auto &str : startWords)
        {
            startLengths[str.size()].push_back(str);
        }

        for (auto &str : targetWords)
        {
            targetLengths[str.size()].push_back(str);
        }
        int res = 0;
        for (auto &str : targetWords)
        {

            for (auto &strs : startLengths[str.size() - 1])
            {
                if (contains(strs, str))
                {
                    res += 1;
                    break;
                }
            }
        }

        return res;
    }
};