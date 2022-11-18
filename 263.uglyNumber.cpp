#include "header.hpp"
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 1)
            return false;
        return solve(n);
    }

    bool solve(int n)
    {
        if (n == 1)
            return true;

        bool by2 = n % 2 == 0;
        bool by3 = n % 3 == 0;
        bool by5 = n % 5 == 0;

        if (!(by2 || by3 || by5))
            return false;

        bool _2 = false, _3 = false, _5 = false;
        if (by2)
            _2 = solve(n / 2);
        if (by3)
            _3 = solve(n / 3);
        if (by5)
            _5 = solve(n / 5);

        return _2 || _3 || _5;
    }
};

int main()
{
    Solution solution;
    cout << solution.isUgly(2);
}