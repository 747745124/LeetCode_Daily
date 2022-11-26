#include "header.hpp"
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<int> monoStack;
        int sum = 0;
        for (int i = 0; i <= arr.size(); i++)
        {
            // whenever the incoming element is smaller than the top or reaches the end
            while (!monoStack.empty() && ((i == arr.size()) || (arr[monoStack.top()] >= arr[i])))
            {
                int item = monoStack.top();
                monoStack.pop();

                int next_smaller_idx = i;
                int prev_smaller_idx = monoStack.empty() ? -1 : monoStack.top();
                sum += arr[item] * (i - item) * (item - prev_smaller_idx);
            }
            monoStack.push(i);
        }

        return sum;
    }
};