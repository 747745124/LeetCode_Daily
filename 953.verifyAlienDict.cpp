#include "header.hpp"
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> pos;
        int _ = 0;
        for (const auto &ch : order)
        {
            pos[ch] = _++;
        }

        for (const auto &word : words)
        {
            int last_pos = -1;
            for (const auto &ch : word)
            {
                if (pos[ch] < last_pos)
                    return false;
                last_pos = pos[ch];
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;
    return 0;
}