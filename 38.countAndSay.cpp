#include "header.hpp"
class Solution
{
public:
    string countAndSay(int n)
    {

        string res = "1";
        // brute force
        for (int i = 0; i < n - 1; i++)
        {
            string temp = "";
            int index = 0;
            bool flag = false;
            while (true)
            {
                int count = 1;
                while (res[index] == res[index + 1])
                {
                    flag = true;
                    count++;
                    index++;
                }
                index++;

                temp += to_string(count);
                temp += res[index - 1];
                if (index == res.size())
                    break;
            }

            res = temp;
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    cout << solution.countAndSay(6) << endl;
    return 0;
}