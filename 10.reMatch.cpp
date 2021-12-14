#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s = "ab";
string p = "aa";
bool regularExpressionMatching(string &s, string &p);

int main()
{
    cout << regularExpressionMatching(s, p) << endl;
}
/*
@params: string s,p
@return: bool
@description: find if two strings are regular expressions matching
*/
bool regularExpressionMatching(string &s, string &p)
{
    //dp[i][j] = string s with len i matches string p with len jdp
    vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
    dp[0][0] = true; //both strings are null

    //p is regular expression
    /*
    s:""
    p:"a*"
    s and p are matched
    */

    for (int i = 1; i <= p.length(); i++)
    {
        if (p.at(i - 1) == '*' && dp[0][i - 2])
        { //修正dp[0][i]，开头情况
            dp[0][i] = true;
        }
    }

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        { //如果i,j相等，或者p.at(j-1)为'.'，则dp[i][j] = dp[i-1][j-1]
            if (p.at(j - 1) == s.at(i - 1) || p.at(j - 1) == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p.at(j - 1) == '*')
            {
                if (p.at(j - 2) != s.at(i - 2) && p.at(j - 2) != '.')
                {
                    dp[i][j] = dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = (dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]);
                }
            }
        }
    }
    return dp[s.length()][p.length()];
}