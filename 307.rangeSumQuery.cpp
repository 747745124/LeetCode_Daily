#include "header.hpp"
class NumArray
{
public:
    // build an array to store the structure, 2n left child, 2n+1 right child.
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        segTree.resize(nums.size() * 2);
        // build tree from leaf nodes (n~2n-1)
        for (int i = n; i < segTree.size(); i++)
        {
            segTree[i] = nums[i - n];
        }
        // build other nodes, leave first index empty
        for (int i = n - 1; i > 0; --i)
        {
            segTree[i] = segTree[i * 2] + segTree[2 * i + 1];
        }
    }

    void update(int index, int val)
    {
        // update the leaf node
        segTree[index + segTree.size() / 2] = val;
        // update other nodes;
        for (int i = ((segTree.size() / 2) + index) / 2; i > 0; i /= 2)
        {
            segTree[i] = segTree[i * 2] + segTree[2 * i + 1];
        }
    }

    int sumRange(int left, int right)
    {
        left += segTree.size() / 2;
        right += segTree.size() / 2;
        int sum = 0;
        while (left <= right)
        {
            if ((left % 2) == 1)
            {
                sum += segTree[left];
                left++;
            }
            if ((right % 2) == 0)
            {
                sum += segTree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

private:
    vector<int> segTree;
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray na(nums);
    cout << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0, 2) << endl;
    return 0;
}