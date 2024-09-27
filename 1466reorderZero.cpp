#include "header.hpp"
class Solution {
public:
    using ADJ_LIST = vector<vector<pair<int,bool>>>;

    int res = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        ADJ_LIST adj_list(n);
        vector<bool> isVisited(n,false);

        for(const auto& con : connections){
            int src = con[0];
            int dest = con[1];
            adj_list[src].push_back(make_pair(dest,true));
            //unreachable by definition, but keep it reachable in dfs process
            adj_list[dest].push_back(make_pair(dest,false));
        }

        dfs(0, isVisited, adj_list);

        return res;
    }

    void dfs(int vertex, vector<bool>&isVisited, ADJ_LIST& adj_list){
        isVisited[vertex] = true;

        for(const auto& adj:adj_list[vertex]){
            if(isVisited[adj.first])
                continue;
            //if you can travel down, there's an edge from parent to child
            //reverse it
            if(adj.second)
                res+=1;
            dfs(adj.first,isVisited,adj_list);
        }
    }

};