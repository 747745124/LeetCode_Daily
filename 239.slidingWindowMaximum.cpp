#include "header.hpp"
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // use a deque, and ensure it's always decreasing
        // only keeps the index
        // remove index of all elements smaller than the current one
        // append current element to the queue

        if (k >= nums.size())
            return {*max_element(nums.begin(), nums.end())};

        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            // clean_queue(i, k);
            dq.push_back(i);
            // compute max in nums[:k]
        }
    }
};