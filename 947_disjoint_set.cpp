#include "header.hpp"

class dj{
public:
    vector<int> dj_set;
    int count;

    dj(int num){
        dj_set.resize(num,-1);
        count = num;
    };

    void setUnion(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x == root_y)
            return;

        int& size_x = dj_set[root_x];
        int& size_y = dj_set[root_y];
        count--;

        if(size_x <= size_y)
        {   
            dj_set[root_x] = root_y;
            size_y = -1*(size_x + size_y);
        }else{
            dj_set[root_y] = root_x;
            size_x = -1*(size_x + size_y);
        }
    };

    int find(int x){
        if(dj_set[x] < 0)
            return x;
        
        return dj_set[x] = find(dj_set[x]);
    }

};

class Solution {
    
public:
    int removeStones(vector<vector<int>>& stones) {
        dj djset(stones.size());

        for(int i = 0; i < stones.size(); i++){
            for(int j = i+1; j < stones.size(); j++){
                if(i==j) continue;

                bool same_x = (stones[i][0] == stones[j][0]);
                bool same_y = (stones[i][1] == stones[j][1]);

                if(same_x || same_y)
                {
                    djset.setUnion(i,j);
                }
            }
        }

        return stones.size()-djset.count;
    }

};