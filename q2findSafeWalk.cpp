#include "header.hpp"
class Solution {
    using Info = pair<int, pair<int, int>>;
    struct Compare {
        bool operator()(const Info& p1, const Info& p2) {
            return (p1.first < p2.first);
        }
    };

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        //dijkstra
        priority_queue<pair<int, pair<int, int>>, Compare> pq;
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        //cost, x, y
        Info start = {grid[0][0], {0, 0}};
        pq.emplace(start);
        vector<int> dirs = {-1,0,1,0,-1};

        while(!pq.empty()) {
            auto [c, p] = pq.top();
            pq.pop();

            int x = p.first;
            int y = p.second;

            if(x == n-1 && y == m-1) return c < health;

            for(int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i+1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nc = c + grid[nx][ny];
                if(nc < cost[nx][ny]) {
                    cost[nx][ny] = nc;
                    Info next = {nc, {nx, ny}};
                    pq.emplace(next);
                }
            }
        }

        return true;
    }
};

