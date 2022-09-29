#include "header.hpp"

class Solution
{
public:
    vector<int> findClosestElements_new(vector<int> &arr, int k, int x)
    {
        vector<int> res;
        int low = 0;
        int high = arr.size() - k - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (abs(x - arr[mid]) > abs(arr[mid + k] - x))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        for (int i = low; i < low + k; i++)
        {
            res.push_back(arr[i]);
        }

        return res;
    };

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> res;
        int closest = modifiedBinarySearch(arr, x);
        k--;
        res.push_back(arr[closest]);
        int low = closest - 1;
        int high = closest + 1;

        while (k != 0 && (low >= 0 || high < arr.size()))
        {
            if (low >= 0 && high < arr.size())
            {
                if (abs((x - arr[low])) > abs((x - arr[high])))
                {
                    res.push_back(arr[high]);
                    high++;
                    k--;
                }
                else if ((abs((x - arr[low])) < abs((x - arr[high]))))
                {
                    res.push_back(arr[low]);
                    low--;
                    k--;
                }
                else
                {
                    res.push_back(arr[low]);
                    low--;
                    k--;
                }
            }

            else if (high >= arr.size())
            {
                res.push_back(arr[low]);
                k--;
                low--;
            }
            else if (low < 0)
            {
                res.push_back(arr[high]);
                k--;
                high++;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }

    int modifiedBinarySearch(vector<int> &arr, int target)
    {
        // after a binary search, the search range will be either 2 numbers(side) or 3 numbers(mid)
        if (target < arr[0])
            return 0;

        if (target > arr.back())
            return arr.size() - 1;

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else if (arr[mid] > target)
                high = mid - 1;
            else
            {
                return mid;
            }
        }

        return (arr[low] - target) < (target - arr[high]) ? low : high;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 1, 10, 10, 10};
    int k = 1;
    int x = 9;
    auto res = s.findClosestElements(arr, k, x);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}