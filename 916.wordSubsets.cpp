#include "header.hpp"
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> charCounts;
        for (auto &word : words2)
        {
            unordered_map<char, int> wordCharCounts;
            for (auto &ch : word)
            {
                wordCharCounts[ch]++;
            }
            for (auto &kv : wordCharCounts)
            {
                charCounts[kv.first] = max(charCounts[kv.first], kv.second);
            }
        }
        vector<string> result;
        for (auto &word : words1)
        {
            bool flag = true;
            unordered_map<char, int> wordCharCounts;
            for (auto &ch : word)
            {
                wordCharCounts[ch]++;
            }

            for (auto &kv : charCounts)
            {
                if (wordCharCounts[kv.first] < charCounts[kv.first])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    vector<string> result = s.wordSubsets(words1, words2);
    for (auto &word : result)
    {
        cout << word << endl;
    }
    return 0;
}