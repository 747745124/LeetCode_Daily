#include "header.hpp"
class Graph
{
public:
    // multiList Representation, using vector
    vector<vector<int>> multiList;
    vector<int> inDegree;
    // initialize
    Graph(int vertexNum, int edgeNum)
    {
        vNum = vertexNum;
        eNum = edgeNum;
        multiList.resize(vertexNum);
        inDegree.resize(vertexNum);
    }

    int getVertexNum() const
    {
        return vNum;
    }
    // insert an edge from src to dst
    void insertEdge(int srcVertex, int dstVertex)
    {
        // make it easier to index
        int src = srcVertex;
        int dst = dstVertex;

        // update parameters
        multiList[src].push_back(dst);
        // multiList[dst].push_back(src);
        inDegree[dst]++;
        // inDegree[src]++;
    };

    bool containsEdge(int srcVertex, int dstVertex) const
    {
        // make it easier to index
        int src = srcVertex;
        int dst = dstVertex;
        // check if the graph contains a certain edge
        if (find(multiList[src].begin(), multiList[src].end(), dst) != multiList[src].end())
            return true;

        return false;
    };

    void print() const
    {
        for (int i = 0; i < multiList.size(); i++)
        {
            cout << i << ": ";
            for (int j = 0; j < multiList[i].size(); j++)
            {
                cout << multiList[i][j] << ' ';
            }
            cout << endl;
        }
    }

private:
    // number of edges and vertices
    int vNum;
    int eNum;
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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
            return false;

        return true;
    }
};