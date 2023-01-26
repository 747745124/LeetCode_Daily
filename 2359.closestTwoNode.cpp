#include "header.hpp"
class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        queue<int> q;
        bitset<100000> is_visited;
        q.push(node1);

        vector<int> dist_1(edges.size(), -1);
        vector<int> dist_2(edges.size(), -1);

        dist_1[node1] = 0;
        dist_2[node2] = 0;
        int level = 0;

        is_visited.set(node1);
        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                auto node = q.front();
                q.pop();

                if (edges[node] != -1 && !is_visited.test(edges[node]))
                {
                    q.push(edges[node]);
                    is_visited.set(edges[node]);
                    dist_1[edges[node]] = level + 1;
                }
            }

            level++;
        }

        q = {};
        is_visited.reset();
        is_visited.set(node2);
        q.push(node2);
        level = 0;

        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                auto node = q.front();
                q.pop();

                if (edges[node] != -1 && !is_visited.test(edges[node]))
                {
                    q.push(edges[node]);
                    is_visited.set(edges[node]);
                    dist_2[edges[node]] = level + 1;
                }
            }

            level++;
        }

        int minmax_dist = INT32_MAX;
        int res = -1;
        for (int i = 0; i < edges.size(); i++)
        {
            if (dist_2[i] == -1 || dist_1[i] == -1)
                continue;

            res = (max(dist_1[i], dist_2[i]) < minmax_dist) ? i : res;
            minmax_dist = min(minmax_dist, max(dist_1[i], dist_2[i]));
        }

        return minmax_dist == INT32_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<int> edges = {4, 4, 8, -1, 9, 8, 4, 4, 1, 1};
    cout << s.closestMeetingNode(edges, 5, 6);
    return 0;
}