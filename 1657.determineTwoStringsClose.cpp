#include "header.hpp"
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (m != n)
            return false;

        unordered_map<char, int> charCount_1, charCount_2;

        for (const auto &ch : word1)
        {
            charCount_1[ch]++;
        }

        for (const auto &ch : word2)
        {
            charCount_2[ch]++;
            if (!charCount_1.count(ch))
                return false;
        }

        // word1 contains a char that word2 doesn't not
        if (charCount_1.size() != charCount_2.size())
            return false;

        // anagram case (case 1)
        if (charCount_1 == charCount_2)
            return true;

        unordered_map<int, int> frequency_1, frequency_2;
        for (const auto &kv : charCount_1)
        {
            frequency_1[kv.second]++;
        }

        for (const auto &kv : charCount_2)
        {
            frequency_2[kv.second]++;
        }

        if (frequency_1 != frequency_2)
            return false;

        return true;
    }
};