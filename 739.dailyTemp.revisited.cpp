#include "header.hpp"
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        stack<int> monoStack;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {

            while (!monoStack.empty() && temperatures[monoStack.top()] < temperatures[i])
            {
                int prev = monoStack.top();
                monoStack.pop();
                result[prev] = i - prev;
            }
            monoStack.push(i);
        }

        return result;
    }
};