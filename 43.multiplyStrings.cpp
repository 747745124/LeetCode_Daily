#include "header.hpp"
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<int> str1;
        vector<int> str2;
        if (num1 == "0" || num2 == "0")
            return "0";
        //conver 2 strings of num in reverse order

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            str1.push_back(num1[i] - '0');
        }

        for (int i = num2.size() - 1; i >= 0; i--)
        {
            str2.push_back(num2[i] - '0');
        }

        vector<int> res(num1.size() + num2.size());
        for (int i = 0; i < str1.size(); i++)
        {
            for (int j = 0; j < str2.size(); j++)
            {
                int tmp = str1[i] * str2[j];
                int idx = i + j;

                res[idx] += tmp % 10;
                res[idx + 1] += tmp / 10;

                if (res[idx] >= 10)
                {
                    res[idx + 1] += res[idx] / 10;
                    res[idx] %= 10;
                }
            }
        }
        string result = "";
        for (int i = 0; i < res.size(); i++)
        {
            result += ('0' + res[i]);
        }
        reverse(result.begin(), result.end());
        //get out of leading zeros

        int i = 0;
        while (result[i] == '0')
        {
            i++;
        }
        result = string(result.begin() + i, result.end());

        return result;
    }
};
int main()
{
    Solution s;
    cout << s.multiply("123", "456");
}