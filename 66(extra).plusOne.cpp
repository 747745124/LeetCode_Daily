class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        int i = digits.size() - 1;
        digits[i] += 1;
        while (digits[i] > 9 && i >= 0)
        {
            if (i == 0 & digits[i] > 9)
            {
                carry = 1;
                break;
            }
            digits[i] = 0;
            digits[i - 1] += 1;
            i--;
        }
        if (digits[0] > 9 && carry)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};