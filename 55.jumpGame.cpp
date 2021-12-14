#include "header.hpp"
// bf
// create a dp array, same length as nums
// zero as dead end
// as long as we don't reach the dead end, we can jump to the end.
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        //end position
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            //this means we can reach the goal from i
            if (i + nums[i] >= goal)
                //shift the goal to i
                goal = i;

            (goal == 0) ? return true : false;
        }
    }
};