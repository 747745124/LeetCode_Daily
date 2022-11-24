#include "header.hpp"
class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        string copy_num = num;
        reverse(num.begin(), num.end());
        for (auto &ch : num)
        {
            if (ch == '6')
                ch = '9';
            else if (ch == '9')
                ch = '6';
        }

        return num == copy_num;
    }
};

int main()
{
    Solution s;
    cout << s.isStrobogrammatic("69") << endl;
}