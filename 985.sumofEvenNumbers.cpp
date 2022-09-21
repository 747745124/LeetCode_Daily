#include "header.hpp"
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<bool> isEven(nums.size(), false);
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                isEven[i] = true;
                currSum += nums[i];
            }
        }

        vector<int> res;
        for (auto &q : queries)
        {
            if ((abs(q[0]) % 2 == 0) && isEven[q[1]] == true) // even+even
            {
                currSum += q[0];
                res.push_back(currSum);
                nums[q[1]] += q[0];
            }
            else if ((abs(q[0]) % 2 == 1) && isEven[q[1]] == false) // odd+odd
            {
                currSum += (q[0] + nums[q[1]]);
                res.push_back(currSum);
                nums[q[1]] += q[0];
                isEven[q[1]] = true;
            }
            else if ((abs(q[0]) % 2 == 1) && isEven[q[1]] == true) // odd+even
            {
                currSum -= nums[q[1]];
                res.push_back(currSum);
                nums[q[1]] += q[0];
                isEven[q[1]] = false;
            }
            else // even+odd
            {
                res.push_back(currSum);
                nums[q[1]] += q[0];
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    auto res = s.sumEvenAfterQueries(nums, queries);
    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}