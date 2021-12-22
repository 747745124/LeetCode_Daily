#include "header.hpp"
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        while (n > 1)
        {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfTwo(-8) << endl;
}