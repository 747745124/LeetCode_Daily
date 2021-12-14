#include "header.hpp"
class Solution
{
public:
    unordered_map<int, int> cache{make_pair(0, 0), make_pair(1, 1), make_pair(2, 1)};

    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (cache[n] != 0)
            return cache[n];

        cache[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

int main()
{
    Solution s;
    cout << s.tribonacci(25) << endl;
}