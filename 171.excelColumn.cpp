#include "header.hpp"
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        uint64_t res = 0;
        for (const auto &ch : columnTitle)
        {
            res = res + ch - 'A' + 1;
            res *= 26;
        }
        res /= 26;

        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.titleToNumber("AB") << endl;
}