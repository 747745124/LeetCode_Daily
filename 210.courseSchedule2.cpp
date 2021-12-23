#include "header.hpp"
/*
this problem is a topological sorting algorithm
build graph and then calculating indegree
*/
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        /* build graph */
        Graph graph(numCourses, prerequisites.size());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph.insertEdge(prerequisites[i][1], prerequisites[i][0]);
        }

        vector<int> res;
        queue<int> indegZero;
        for (int i = 0; i < numCourses; i++)
        {
            if (graph.inDegree[i] == 0)
                indegZero.push(i);
        }

        while (!indegZero.empty())
        {
            int cur = indegZero.front();
            indegZero.pop();
            res.push_back(cur);
            for (int i = 0; i < graph.multiList[cur].size(); i++)
            {
                int next = graph.multiList[cur][i];
                graph.inDegree[next]--;
                if (graph.inDegree[next] == 0)
                    indegZero.push(next);
            }
        }
        // has a cycle
        if (res.size() != numCourses)
            return {};

        return res;
    }
};
