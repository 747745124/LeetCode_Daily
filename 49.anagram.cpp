#include "header.hpp"
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // for each string, generate word count of 26 chars[]
        // concantenate word alphabetically
        // keep a dictionary [wordCount] = vector of strings

        // for each string, generate canonical form
        // dict[canonical].append(str), index with the canonical form
        // push back to a vector
        //  canonical form will be: char+count(char), e.g. aabbc, a2b2c1

        unordered_map<string, vector<string>> dict;
        vector<vector<string>> res;
        for (const auto &str : strs)
        {
            vector<int> wordCount(26, 0);
            for (const auto &ch : str)
                wordCount[ch - 'a']++;

            string canonical;
            for (int i = 0; i < wordCount.size(); i++)
            {
                if (wordCount[i] == 0)
                    continue;
                else
                    canonical += string(1, i + 'a') + to_string(wordCount[i]);
            }
            dict[canonical].push_back(str);
        }
        
        // convert a map to vector
        // value is vector<vector<string>>
        for (auto &kv : dict)
        {
            res.push_back(kv.second);
        }

        return res;
    }
};