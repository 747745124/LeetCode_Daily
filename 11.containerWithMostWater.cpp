#include "header.hpp"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int res = 0;

        while (l < r)
        {
            int width = r - l;
            int h = min(height[l], height[r]); // find the smaller height
            int area = width * h;

            res = max(res, area); // update result
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return res;
    }
};