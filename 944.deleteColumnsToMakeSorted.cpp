#include "header.hpp"
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int res = 0;

        for (int i = 0; i < strs[0].size(); i++)
        {
            auto curr_char = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                // not sorted
                if (curr_char > strs[j][i])
                {
                    res++;
                    break;
                }
                curr_char = strs[j][i];
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"cba", "daf", "ghi"};
    cout << s.minDeletionSize(strs) << endl;
    return 0;
}