#include "header.hpp"
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        /*
        the single non duplicate must exist in the non-even half
        1,2,2,4,4,5,5 -> middle = 4, middle = middle+1, so check left
        1,1,2,2,4,4,5 -> middle = 2, middle = middle-1, so check right
        */
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            bool isLeftEvenSize = (mid - left) % 2 == 0;

            if (mid + 1 < n && nums[mid] == nums[mid + 1])
                if (isLeftEvenSize)
                    left = mid + 2;
                else
                    right = mid - 1;

            else if (mid && nums[mid] == nums[mid - 1])
                if (isLeftEvenSize)
                    right = mid - 2;
                else
                    left = mid + 1;

            else
                return nums[mid];
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}