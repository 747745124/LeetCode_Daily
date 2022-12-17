#include "header.hpp"
class Solution
{
public:
    int minDist = INT32_MAX;
    int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
    {
        int n = workers.size();
        int m = bikes.size();
        bitset<10> isOccupied;
        dfs(workers, bikes, 0, 0, isOccupied);
        return minDist;
    }

    void dfs(vector<vector<int>> &workers, vector<vector<int>> &bikes, int currDist, int workerIndex, bitset<10> &isOccupied)
    {
        // all nodes have been found
        if (workerIndex >= workers.size())
        {
            minDist = min(minDist, currDist);
        }

        if (currDist >= minDist)
            return; // pruning

        for (int i = 0; i < bikes.size(); i++)
        {
            if (!isOccupied.test(i))
            {
                isOccupied.set(i);
                dfs(workers, bikes, currDist + helper(workers[workerIndex][0], workers[workerIndex][1], bikes[i][0], bikes[i][1]), workerIndex + 1, isOccupied);
                isOccupied.reset(i);
            }
        }
    }

    int helper(int w_1, int w_2, int b_1, int b_2)
    {
        return abs(w_1 - w_2) + abs(b_1 - b_2);
    }
};