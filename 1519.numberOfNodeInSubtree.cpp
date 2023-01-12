#include "header.hpp"
class graph
{
public:
    graph(int n)
    {
        adj_list.resize(n);
    };

    vector<vector<int>> adj_list;
    // since the subtree definition stays the same, it's actually better to use directed graph
    // handle as DAG
    void insert_edge(int src, int dst)
    {
        adj_list[src].push_back(dst);
        adj_list[dst].push_back(src);
        return;
    };
};

class Solution
{
public:
    int *dfs(int node, int parent, graph &g, string &labels,
             vector<int> &res)
    {

        // Store count of all alphabets in the subtree of the node.
        int nodeCounts[26] = {0};
        nodeCounts[labels[node] - 'a'] = 1;
        for (auto &child : g.adj_list[node])
        {
            if (child == parent)
                continue;
            int *childCounts = new int[26];
            childCounts = dfs(child, node, g, labels, res);
            for (int i = 0; i < 26; i++)
            {
                nodeCounts[i] += childCounts[i];
            }
        }

        res[node] = nodeCounts[labels[node] - 'a'];
        return nodeCounts;
    };

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        graph g(n);
        for (auto &edge : edges)
        {
            g.insert_edge(edge[0], edge[1]);
        }

        vector<int> res = {};
        res.resize(n);

        dfs(0, -1, g, labels, res);

        return res;
    }
};