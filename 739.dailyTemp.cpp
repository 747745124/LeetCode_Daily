#include "header.hpp"
/*
return an array answer such that answer[i] is the 
number of days you have to wait after the ith day 
to get a warmer temperature. If there is no future 
day for which this is possible, keep answer[i] == 0 instead.
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);

        //store index and temperature pair
        stack<pair<int, int>> myStack;
        for (int i = 0; i < temperatures.size(); i++)
        {
            //if there is one day warmer, pop until no day is warmer
            while (!myStack.empty() && (temperatures[i] > myStack.top().second))
            {
                res[myStack.top().first] = i - myStack.top().first;
                myStack.pop();
            }

            myStack.push(make_pair(i, temperatures[i]));
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}