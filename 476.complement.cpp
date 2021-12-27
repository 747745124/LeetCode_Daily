#include "header.hpp"
class Solution
{
public:
    int findComplement(int num)
    {
        int mask = 1;
        while (mask < num)
        {
            // right shift once and plus one
            // 1 -> 11 -> 111 -> 1111 -> 11111 -> 111111
            mask = (mask << 1) + 1;
        }
        // doing a bitwise xor
        // 111 xor 101 = 010
        return mask ^ num;
    }
};

int main()
{
    Solution s;
    cout << s.findComplement(5) << endl;
    return 0;
}