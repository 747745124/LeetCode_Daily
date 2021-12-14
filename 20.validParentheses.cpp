#include "header.hpp"
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> charStack;
        charStack.push(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (charStack.empty())
            {
                charStack.push(s[i]);
                continue;
            }
            if (isPair(charStack.top(), s[i]))
            {
                charStack.pop();
            }
            else
            {
                charStack.push(s[i]);
            }
        }
        if (charStack.empty())
            return true;
        return false;
    }
    bool isPair(char ch1, char ch2)
    {
        if (ch1 == '(' && ch2 == ')')
            return true;
        if (ch1 == '[' && ch2 == ']')
            return true;
        if (ch1 == '{' && ch2 == '}')
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("(){}}{");
}