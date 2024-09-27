#include "header.hpp"
class Solution {
     bool increasingTriplet2(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        // m1 is the local minimum
        // once m2 is updated, there will be at least one number smaller than m2
        // if there is a number bigger than m2, then there will be a triplet
        int m1 = INT_MAX;
        int m2 = INT_MAX;

        for (const auto &num : nums)
        {
            // update m1
            if (num < m1)
            {
                m1 = num;
                continue;
            }
            // m2 is the second smallest number
            if (num < m2 && num > m1)
            {
                m2 = num;
                continue;
            }

            if (num > m2)
                return true;
        }

        return false;
    }
}