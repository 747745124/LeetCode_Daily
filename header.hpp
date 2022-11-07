#pragma once
#include <iterator>
#include <type_traits>
#include <utility>
#include <math.h>
#include <random>
#include <stdint.h>
#include <cstdint>
#include <numeric>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <memory>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <ctype.h>
using namespace std;

template <typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:
    bool remove(const T &value)
    {
        auto it = std::find(this->c.begin(), this->c.end(), value);

        if (it == this->c.end())
        {
            return false;
        }
        if (it == this->c.begin())
        {
            // deque the top element
            this->pop();
        }
        else
        {
            // remove element and re-heap
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
        }
        return true;
    }
};

struct ListNodeD // doubly linked list node
{
    std::pair<int, int> val;
    ListNodeD *next;
    ListNodeD *prev;
    ListNodeD() : val(0, 0), next(nullptr), prev(nullptr) {}
    ListNodeD(int x, int y) : val(x, y), next(nullptr), prev(nullptr) {}
    ListNodeD(int x, int y, ListNodeD *next, ListNodeD *prev) : val(x, y), next(next), prev(prev) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class DisjointSet
{
public:
    // union by size
    DisjointSet(int n)
    {
        for (int i = 0; i < n; i++)
            set.push_back(-1);
        componentCount = n;
    }

    // overloaded with std::find
    int find(int elem)
    {
        if (set[elem] < 0)
            return elem;
        // with compression
        return set[elem] = find(set[elem]);
    }

    // implement union function, union is a reserved key word
    void setUnion(int x, int y)
    {
        if (x == y)
            return;
        componentCount -= 1;
        int rootX = find(x);
        int rootY = find(y);
        int sizeX = (set[rootX]);
        int sizeY = (set[rootY]);

        if (sizeX >= sizeY)
        {
            // connect Y to X
            set[rootY] = rootX;
            // update size
            set[rootX] = -1 * (sizeY + sizeX);
            return;
        }
        // connect X to Y
        set[rootX] = rootY;
        // update size
        set[rootY] = -1 * (sizeY + sizeX);
        return;
    }

    int getCount()
    {
        return componentCount;
    }

    vector<long> set;

private:
    int componentCount;
};

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
        multiList[dst].push_back(src);
        inDegree[dst]++;
        inDegree[src]++;
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

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};