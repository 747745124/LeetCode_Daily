#include "header.hpp"

class Solution
{
public:
    vector<vector<int>> graph;
    int res = 0;

    int countComponents(int n, vector<vector<int>> &edges)
    {
        graph.resize(n);

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++)
        {
            res += visit(i, isVisited);
        }

        return res;
    }

    bool visit(int i, vector<bool> &isVisited)
    {
        if (isVisited[i] != false)
        {
            return false;
        }

        isVisited[i] = true;
        for (auto &dest : graph[i])
            visit(dest, isVisited);

        return true;
    };
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}};
    cout << s.countComponents(2, edges) << endl;
    return 0;
}