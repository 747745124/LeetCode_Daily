#include "header.hpp"

class Solution
{
public:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int> &nums)
    {
        // two pointers

        int low = -1;
        int high = nums.size();
        int i = 0;
        // keeps 0 to low to be 0
        // low+1 to ptr to be 1
        // high to end to be 2

        while (i < high)
        {
            if (nums[i] == 0)
            {
                low++;
                swap(nums, i, low);
                i++;
            }
            else if (nums[i] == 2)
            {
                high--;
                swap(nums, i, high);
            }
            else
            {
                i++;
            }
        }
    }
};