#include "header.hpp"
class Solution {
    vector<bool> is_visited;
public:
    int removeStones(vector<vector<int>>& stones) {


        int num_cc = 0;
        vector<unordered_set<int>> adj_list(stones.size());
        is_visited = vector<bool>(stones.size(),false);

        for(int i = 0; i < stones.size(); i++){
            for(int j = 0; j < adj_list.size(); j++){
                if(i==j) continue;

                bool same_x = (stones[i][0] == stones[j][0]);
                bool same_y = (stones[i][1] == stones[j][1]);

                if(same_x || same_y)
                {
                    adj_list[i].insert(j);
                    adj_list[j].insert(i);
                }
            }
        }

        for(int i = 0; i < adj_list.size(); i++){

            if(!is_visited[i])
            {
                dfs(adj_list,i);
                num_cc++;
            }
        }

        return adj_list.size()-num_cc;

    }

    private:
    void dfs(vector<unordered_set<int>>& adj_list,int visit){
        is_visited[visit] = true;
        for(const auto&stone : adj_list[visit]){
            if(!is_visited[visit])
                dfs(adj_list,stone);
        }

    }
};