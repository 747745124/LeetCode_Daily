#include "header.hpp"
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> visitedRooms;
        queue<int> q;

        q.push(0);
        visitedRooms.insert(0);
        while (!q.empty())
        {
            int room = q.front();
            q.pop();
            visitedRooms.insert(room);
            for (int key : rooms[room])
            {
                if (!visitedRooms.count(key))
                {
                    q.push(key);
                }
            }
        }
        return visitedRooms.size() == rooms.size();
    }
};