#include "header.hpp"
class Solution
{
public:
    bool confusingNumber(int n)
    {
        int new_num = 0;
        int org_num = n;
        while (n)
        {
            int digit = n % 10;
            vector<int> invalid = {2, 3, 4, 5, 7};

            if (count(invalid.begin(), invalid.end(), digit))
                return false;

            switch (digit)
            {
            case 0:
                digit = 0;
                break;
            case 1:
                digit = 1;
                break;
            case 6:
                digit = 9;
                break;
            case 8:
                digit = 8;
                break;
            case 9:
                digit = 6;
                break;
            default:
                break;
            }

            new_num += digit;
            new_num *= 10;
            n /= 10;
        }
        new_num /= 10;

        return new_num != org_num;
    }
};

int main()
{
    Solution sol;
    cout << sol.confusingNumber(11) << endl;
    return 0;
}