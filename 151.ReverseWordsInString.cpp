#include "header.hpp"
class Solution
{
public:
    string reverseWords(string s)
    {

        vector<string> words;
        istringstream ss(s);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }

        word.clear();

        for (int i = words.size() - 1; i > 0; i--)
        {
            word += words[i];
            word += " ";
        }

        word += words[0];

        return word;
    }
};

int main()
{
    Solution solution;
    solution.reverseWords("  What   the fuck");
}