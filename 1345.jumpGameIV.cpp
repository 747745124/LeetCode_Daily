#include "header.hpp"

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        //<value,position>
        unordered_map<int, vector<int>> sameValueSet;
        for (int i = 0; i < arr.size(); i++)
        {
            sameValueSet[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<int> shortestPath(arr.size(), INT32_MAX);
        shortestPath[0] = 0;

        if (arr.size() == 1)
        {
            return 0;
        }

        q.push(make_pair(0, 1));
        for (const auto &i : sameValueSet[arr[0]])
        {
            if (i != 0)
                q.push(make_pair(0, i));
        }

        while (!q.empty())
        {
            auto [src, dest] = q.front();
            q.pop();
            shortestPath[dest] = min(shortestPath[dest], shortestPath[src] + 1);
            if (dest == arr.size() - 1)
                return shortestPath[dest];

            for (const auto &newDest : sameValueSet[arr[dest]])
            {
                if (shortestPath[newDest] == INT32_MAX)
                    q.push(make_pair(dest, newDest));
            }
            sameValueSet[arr[dest]].clear();

            if (dest > 0 && shortestPath[dest - 1] == INT32_MAX)
                q.push(make_pair(dest, dest - 1));
            if (dest < (arr.size() - 1) && shortestPath[dest + 1] == INT32_MAX)
                q.push(make_pair(dest, dest + 1));
        }

        return shortestPath[arr.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << s.minJumps(arr) << endl;
    return 0;
}