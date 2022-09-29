#include "header.hpp"
class Solution
{
public:
    int getLog(uint64_t n)
    {
        int res = 0;
        while ((n >>= 1))
            res++;

        return res + 1;
    }

    int concatenatedBinary(int n)
    {
        uint64_t res = 0;
        int num = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            int length = getLog(i);
            res = ((res << length) % num + i) % num;
        }

        return res;
    }
};

int main()
{
    Solution s;
    cout << s.concatenatedBinary(12) << endl;
    return 0;
}