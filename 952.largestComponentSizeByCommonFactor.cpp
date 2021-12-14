#include "header.hpp"
class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        DisjointSet disSet(*max_element(nums.begin(), nums.end()) + 1);
        for (const auto &i : nums)
        { //factorize the i
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    //the number shares the least common denominator
                    disSet.setUnion(j, i);
                    disSet.setUnion(i / j, i);
                }
            }
        }

        int res = 1;
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            int p = disSet.find(i);
            freq[p]++;
            res = max(res, freq[p]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {20, 50, 9, 63};
    cout << s.largestComponentSize(nums) << endl;
}