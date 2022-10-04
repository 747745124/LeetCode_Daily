#include "header.hpp"
class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> zeros;
        for (int i = 0; i < s.size(); i++)
        {
            if (!zeros.empty() && s[i] == '0' && zeros.back() == (i - 1)) // consecutive 0s
                return 0;
            if (s[i] == '0')
                zeros.push_back(i);
        }

        if (!zeros.empty() && zeros[0] == 0)
            return 0; // initial zero

        // preprocess string
        for (const auto &zero_pos : zeros)
        {
            auto temp = s[zero_pos - 1];
            if ((temp - '0') >= 3)
                return 0;

            s.erase(zero_pos - 1, 2); // 32204->324
        }

        cout << s;
        return 0;
    }
};

int main()
{
    Solution solution;
    solution.numDecodings("32204");
}