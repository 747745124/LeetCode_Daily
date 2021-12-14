#include "header.hpp"
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> presence;
        vector<string> res;
        if (s.size() <= 10)
            return {};
        for (int i = 0; i < s.size() - 9; i++)
        {
            string tmp = string(s.begin() + i, s.begin() + i + 10);
            if (presence.count(tmp) == 0)
                presence[tmp]++;
            else if (presence.at(tmp) == 1)
            {
                presence[tmp]++;
                res.push_back(tmp);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
}