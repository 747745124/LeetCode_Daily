#include "header.hpp"
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq(piles.begin(), piles.end());
        int sum = std::accumulate(piles.begin(), piles.end(), 0);

        for (int i = 0; i < k; i++)
        {
            int stone = pq.top();
            pq.pop();

            sum -= stone / 2;
            pq.push(stone - stone / 2);
        }

        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {5, 4, 9};
    int k = 2;
    cout << s.minStoneSum(piles, k) << endl;
    return 0;
}