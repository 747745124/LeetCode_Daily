#include "header.hpp"
// find the minimum absolute difference and return all of pairs with the min difference
// a sorting base strategy, O(nlogn)
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());
        vector<int> diff(arr.size());

        diff[0] = INT16_MAX;
        int minDiff = INT32_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            diff[i] = arr[i] - arr[i - 1];
            if (diff[i] < minDiff)
                minDiff = diff[i];
        }

        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++)
        {
            if (diff[i] == minDiff)
                res.push_back(vector<int>{arr[i - 1], arr[i]});
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {4, 2, 1, 3};
    s.minimumAbsDifference(arr);
}