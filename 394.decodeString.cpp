#include "header.hpp"

/*
Input : s = "3[a]2[bc]" Output : "aaabcbc"
Input: s = "3[a2[c]]" Output: "accaccacc"
Input: s = "2[abc]3[cd]ef" Output: "abcabccdcdcdef"
*/

/* Overloading * operator */
string operator*(string a, unsigned int b)
{
    string output = "";
    while (b--)
    {
        output += a;
    }
    return output;
}

class Solution
{
public:
    string solve(string s, int n, int &i)
    {
        string tmp = "";
        // check limits and ending of a recursion,
        while (i < n && s[i] != ']')
        {

            if (s[i] >= 'a' && s[i] <= 'z')
            {
                tmp += s[i];
                i += 1;
            }
            else
            {
                int number = 0;
                // forming the number (the number of times we have to repeat the string)
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }

                i += 1; // skip '['
                // recursively solve smaller [] block
                string res = solve(s, n, i);
                i += 1; // skip ']'

                tmp += res * number;
            }
        }

        return tmp;
    }

    string decodeString(string s)
    {
        int inx = 0;
        int n = s.length();
        return solve(s, n, inx);
    }
};

int main()
{
    Solution s;
    string s2 = "2[abc]3[cd]";
    cout << s.decodeString(s2) << endl;
    return 0;
}