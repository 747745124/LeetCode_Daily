#include "header.hpp"
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // binary search for the eating speed
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right)
        {
            int middle = (left + right) * 0.5;
            int hourSpent = 0;

            for (const auto &p : piles)
            {
                hourSpent += p / middle + (p % middle != 0);
            }

            // if hour spent is less, I can eat slower
            // search in the lower middle
            if (hourSpent <= h)
                right = middle;
            // if hour spent is greater, I should eat faster
            else
                left = middle + 1;
        }

        return right;
    }
};