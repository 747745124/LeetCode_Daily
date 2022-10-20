#include "header.hpp"
class Solution
{
public:
    string intToRoman(int num)
    {
        string res = "";
        int count = 0;
        if (num >= 1000)
            count = num / 1000;
        for (int i = 0; i < count; i++)
            res += "M";

        count = 0;
        num %= 1000;
        if (num >= 100)
        {
            count = num / 100;
            if (count == 9)
            {
                res += "CM";
                num -= 900;
            }
            else if (count >= 5)
            {
                res += "D";
                count -= 5;
                for (int i = 0; i < count; i++)
                    res += "C";
                num %= 100;
            }
            else if (count == 4)
            {
                res += "CD";
                num -= 400;
            }
            else
            {
                for (int i = 0; i < count; i++)
                    res += "C";
                num %= 100;
            }
            count = 0;
        }

        if (num >= 10)
        {
            count = num / 10;
            if (count == 9)
            {
                res += "XC";
                num -= 90;
            }
            else if (count >= 5)
            {
                res += "L";
                count -= 5;
                for (int i = 0; i < count; i++)
                    res += "X";
                num %= 10;
            }
            else if (count == 4)
            {
                res += "XL";
                num -= 40;
            }
            else
            {
                for (int i = 0; i < count; i++)
                    res += "X";
                num %= 10;
            }
            count = 0;
        }

        count = num;
        if (count == 9)
        {
            res += "IX";
        }
        else if (count >= 5)
        {
            res += "V";
            count -= 5;
            for (int i = 0; i < count; i++)
                res += "I";
        }
        else if (count == 4)
        {
            res += "IV";
        }
        else
        {
            for (int i = 0; i < count; i++)
                res += "I";
        }
        return res;
    }
};