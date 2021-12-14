#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s = "aaa";
string p = "a**";
bool regularExpressionMatching(string &s, string &p);
bool dfs(int i, int j);
// vector<vector<bool> > cache(s.length() + 1, vector<bool>(p.length() + 1, false));

int main()
{
    cout << regularExpressionMatching(s, p) << endl;
}

bool regularExpressionMatching(string &s, string &p)
{
    return dfs(0, 0);
}

bool dfs(int i, int j)
{
    if (i > s.length() && j > p.length())
        return true;
    if (j > p.length())
        return false;
    // in bounds and match
    bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

    //handling the star
    if (j + 1 < p.length() && p[j + 1] == '*')
        return dfs(i, j + 2) || (dfs(i + 1, j) && match);
    //handling basic case
    if (match)
        return dfs(i + 1, j + 1);
    return false;
}