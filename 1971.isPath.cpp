#include "header.hpp"
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // bitset<20000> isVisited;
        unordered_set<int> isVisited;
        isVisited.insert(source);
        queue<int> q;

        q.push(source);
        while (!q.empty())
        {

            auto node = q.front();
            q.pop();
            isVisited.insert(node);
            if (node == destination)
                return true;

            for (const auto &dest : graph[node])
            {
                if (!isVisited.count(dest))
                {
                    q.push(dest);
                }
            }
        }

        return false;
    }
};
