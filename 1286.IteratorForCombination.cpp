#include "header.hpp"
class CombinationIterator
{
public:
    //it's all about how to get all combinations
    CombinationIterator(string characters, int combinationLength)
    {
        strLen = characters.size();
        privateString = characters;
        getCombinations(0, combinationLength, "");
    }

    string next()
    {
        string tmp = deq.front();
        deq.pop();
        return tmp;
    }

    bool hasNext()
    {
        return !deq.empty();
    }

private:
    void getCombinations(int start, int length, string text)
    {
        if (length == 0)
        {
            deq.push(text);
            return;
        }

        for (int i = start; i < strLen; i++)
        {
            getCombinations(i + 1, length - 1, text + privateString[i]);
        }
    }

    queue<string> deq;
    int strLen = 0;
    string privateString;
};