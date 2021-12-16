#include "header.hpp"
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // The most important thing to know is that there is at most 2 of such root
        // These roots have the least overall distance of leaves.
        // And these roots have the same rank (A vague concept)
        // being equivalent.
        // If a tree have 3 or more such roots, these roots must form a cycle
        // the graph can't be tree
        // also if any of the edge removed from the roots, the cycle will be downgrade to chain like
        // thus having 1 or 2 roots.
        // this problem is actually a variant of the topological sort algorithm

        Graph graph(n, edges.size());
        for (int i = 0; i < edges.size(); i++)
        {
            graph.insertEdge(edges[i][0], edges[i][1]);
        }

        queue<int> topoBox;
        vector<bool> output(n, false);
        int outputNum = n;
        vector<int> res;

        std::function<int(int)> maxHeight = [&](int root)
        {
            vector<int> next;
            vector<int> curr;
            curr.push_back(root);
            vector<bool> isVisited(n, false);
            int height = 0;

            while (!curr.empty())
            {
                next.clear();

                int flag = false;
                for (const auto &cur : curr)
                {
                    isVisited[cur] = true;
                    for (auto &neighbor : graph.multiList[cur])
                    {
                        if (isVisited[neighbor] == false)
                        {
                            next.push_back(neighbor);
                            flag = true;
                        }
                    }
                }

                swap(next, curr);

                if (flag)
                {
                    height++;
                }
            }

            return height;
        };

        for (int i = 0; i < n; i++)
        {
            // these are the leaf nodes
            if (graph.inDegree[i] == 1)
            {
                topoBox.push(i);
            }
        }

        while (outputNum > 2)
        {
            int currVertex = topoBox.front();
            topoBox.pop();
            output[currVertex] = true;
            outputNum--;
            for (const auto &node : graph.multiList[currVertex])
            {
                graph.inDegree[node]--;
                if (graph.inDegree[node] == 1)
                {
                    topoBox.push(node);
                }
            }
        }

        if (outputNum == 2)
        {
            int t1 = topoBox.front();
            int t2 = topoBox.back();
            auto height1 = maxHeight(t1);
            auto height2 = maxHeight(t2);
            if (height1 == height2)
                return vector<int>{t1, t2};
            if (height1 > height2)
                return vector<int>{t2};
            else
                return vector<int>{t1};
        }

        for (const auto &node : output)
        {
            if (node == false)
                res.push_back(node);
        }

        return res;
    };
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {2, 0}, {0, 3}, {3, 4}, {4, 5}};
    vector<int> res = s.findMinHeightTrees(6, edges);
    for (const auto &node : res)
    {
        cout << node << ' ';
    }
    cout << endl;
    return 0;
}