#include "header.hpp"
class Solution
{
public:
    bool matching(unordered_map<char, int> &words1, unordered_map<char, int> &words2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (words1[i + 'a'] != words2[i + 'a'])
                return false;
        }
        return true;
    };

    bool checkInclusion(string s1, string s2)
    { // sliding window
        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> words1, words2;
        for (int i = 0; i < s1.length(); i++)
        {
            words1[s1[i]]++;
            words2[s2[i]]++;
        }

        for (int i = 0; i <= s2.length() - s1.length(); i++)
        {
            if (matching(words1, words2))
                return true;
            words2[s2[i + s1.length()]]++;
            words2[s2[i]]--;
        }

        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl;
    return 0;
}