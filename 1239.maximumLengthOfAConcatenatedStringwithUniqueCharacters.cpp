#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /*
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
*/
    int maxLength(vector<string> &arr)
    {
        //valid string
        vector<int> a;
        for (const string &x : arr)
        {
            //bit representations
            int mask = 0;
            for (const auto ch : x)
            {
                //bit representation
                mask |= 1 << (ch - 'a');
            }

            //if the char used != the length of string, it contains duplicates.
            //ignore the string
            if (__builtin_popcount(mask) != x.length())
                continue;

            a.push_back(mask);
        }

        //s is the index of string, mask is the present state
        int ans = 0;
        function<void(int, int)> dfs = [&](int s, int mask)
        {
            //update the result
            ans = max(ans, __builtin_popcount(mask));
            for (int i = s; i < a.size(); i++)
            {
                //if the result is valid
                if (__builtin_popcount(mask & a[i]) == 0)
                    //go to combine with next element
                    dfs(i + 1, mask | a[i]);
            }
        };

        dfs(0, 0);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<string> hey = {"as", "is", "it", "god", "howmuc"};
    cout << sol.maxLength(hey);
}