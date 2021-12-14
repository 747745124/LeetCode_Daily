#include "header.hpp"
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        //a mapping from char to string
        unordered_map<char, string> dict;
        unordered_set<string> words;
        unordered_set<char> chs;
        vector<string> vWord;

        int count = 0;
        string delimiter = " ";
        size_t last = 0;
        size_t next = 0;
        while ((next = s.find(delimiter, last)) != string::npos)
        {
            words.insert(s.substr(last, next - last));
            vWord.push_back(s.substr(last, next - last));
            last = next + 1;
            count++;
        }
        words.insert(s.substr(last));
        vWord.push_back(s.substr(last));
        count++;

        if (count != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
        {
            chs.insert(pattern[i]);
        }

        if (chs.size() != words.size())
            return false;

        for (int i = 0; i < vWord.size(); i++)
        {
            if (dict[pattern[i]].empty())
                dict[pattern[i]] = vWord[i];
            else if (vWord[i] != dict[pattern[i]])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.wordPattern("aba", "dog cat cat");
}