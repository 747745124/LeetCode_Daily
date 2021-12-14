#pragma once
#include <iterator>
#include <type_traits>
#include <utility>
#include <numeric>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <string>
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

using namespace std;

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
        componentCount -= 1;
        int rootX = find(x);
        int rootY = find(y);
        int sizeX = abs(set[rootX]);
        int sizeY = abs(set[rootY]);

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

private:
    vector<int> set;
    int componentCount;
};