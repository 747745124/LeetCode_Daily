#include "header.hpp"
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj_list(n);
        using triplet = tuple<int, int, int>;
        for (const auto &flight : flights)
        {
            adj_list[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }

        // cum_dist, node, cum_stops
        priority_queue<triplet, vector<triplet>, greater<triplet>> pq;
        vector<int> stops(n, INT32_MAX);

        pq.push({0, src, 0});

        while (pq.size() > 0)
        {
            auto [cum_dist, node, cum_steps] = pq.top();
            pq.pop();

            if (cum_steps > stops[node] || cum_steps > k + 1)
                continue;

            stops[node] = cum_steps;
            if (node == dst)
                return cum_dist;

            for (const auto &[dest, price] : adj_list[node])
            {
                pq.push({cum_dist + price, dest, cum_steps + 1});
            }
        }

        return -1;
    }
};