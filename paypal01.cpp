#include "header.hpp"

int pairOf60(vector<int> &nums)
{
    unordered_map<int, int> presences; // length,times
    int res = 0;
    for (auto &num : nums)
    {

        res += presences[(60 - (num % 60)) % 60];
        presences[num % 60]++;
    }
    return res;
}

int main()
{
    vector<int> nums = {60, 60, 60};
    cout << pairOf60(nums);
    return 0;
}