#include "header.hpp"
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {

        stringstream ss(sentence);
        string word;
        vector<string> words;

        while (ss >> word)
        {
            words.push_back(word);
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (words[i].back() != words[i + 1].front())
                return false;
        }

        if (words[words.size() - 1].back() != words[0].front())
            return false;

        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isCircularSentence("eetcode");
    return 0;
}