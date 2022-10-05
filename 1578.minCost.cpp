#include "header.hpp"
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int prev = 0;
        int curr = 1;
        int res = 0;

        while (curr < neededTime.size())
        {
            priority_queue<int, vector<int>, std::greater<int>> pq;
            int nums = 0;

            bool flag = false;
            while (colors[prev] == colors[curr])
            {
                pq.push(neededTime[prev]);
                nums++;
                prev++;
                curr++;
                flag = true;
            }
            if (flag)
                pq.push(neededTime[prev]);

            while (nums--)
            {
                res += pq.top();
                pq.pop();
            }

            if (!flag)
            {
                prev++;
                curr++;
            }
        }

        return res;
    }
};

int main()
{

    Solution s;
    vector<int> m = {1, 2, 3, 4, 1};
    cout << s.minCost("aabaa", m) << endl;

    return 0;
}