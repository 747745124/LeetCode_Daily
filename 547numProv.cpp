#include "header.hpp"
class Solution {
public:

    class DJSet{
        public:
            DJSet(int num){
                dj_set = vector<int>(num,-1);
                component = num;
            }

            int find(int x){

                if(dj_set[x]<0)
                    return x;
                //path compression
                return dj_set[x] = find(dj_set[x]);

            };

            void set_union(int x, int y){

                int root_x = find(x);
                int root_y = find(y);
                int size_x = abs(dj_set[root_x]);
                int size_y = abs(dj_set[root_y]);

                if(root_x==root_y)
                    return;

                if(size_x >= size_y)
                {
                    dj_set[root_y] = root_x;
                    dj_set[root_x] = -1*(size_x+size_y);
                }else{
                    dj_set[root_x] = root_y;
                    dj_set[root_y] = -1*(size_x+size_y);
                }

                component--;
                return;
            };

        int component;

        private:
            vector<int> dj_set;
    };


    int findCircleNum(vector<vector<int>>& isConnected) {
        DJSet dj(isConnected.size());
        for(int i=0; i < isConnected.size();i++){
            for(int j=i+1;j < isConnected.size();j++){
                if(isConnected[i][j]==1)
                    dj.set_union(i,j);
            }
        }

        return dj.component;
    }
};