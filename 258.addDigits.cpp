#include "header.hpp"
class Solution
{
public:
    int addDigits(int num)
    {
        while (num > 9)
        {
            int n = num;
            int res = 0;
            while (n)
            {
                res += n % 10;
                n /= 10;
            }

            num = res;
        }

        return num;
    }
};

int main()
{
    Solution s;
    cout << s.addDigits(38) << endl;
    return 0;
}
