#include "header.hpp"
class Solution
{
public:
    int connectSticks(vector<int> &sticks)
    {
        priority_queue<int, vector<int>, std::greater<int>> pq(sticks.begin(), sticks.end());
        int cost = 0;
        while (pq.size() >= 2)
        {
            int cost_1 = pq.top();
            pq.pop();

            int cost_2 = pq.top();
            pq.pop();

            cost += cost_1;
            cost += cost_2;

            pq.push(cost_1 + cost_2);
        }

        return cost;
    }
};