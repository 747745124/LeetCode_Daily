#include "header.hpp"

class Solution {
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int fresh = 0;
        vector<std::pair<int,int>> curr,next;

        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                int e = grid[i][j];
                if(e!=0)
                    fresh++;
                if(e==2)
                    curr.push_back(make_pair(i,j));

            }
        }

        const auto isValid = [&](int i, int j){
            if(i>=grid.size()||i<0||j>=grid[0].size()||j<0)
                return false;
            return true;
        };

        const vector<int> dirs = {-1,0,1,0,-1};

        while(!curr.empty()){
            fresh -= curr.size();

            for(const auto&ij:curr){
                int i = ij.first;
                int j = ij.second;
                grid[i][j] = 2;

                for(int k=0;k<4;k++)
                {
                    int dx = dirs[k];
                    int dy = dirs[k+1];

                    if(isValid(i+dx,j+dy)&&grid[i+dx][j+dy]==1)
                        next.push_back(make_pair(i+dx,j+dy));
                }


            }
                            curr = next;
                next.clear();

            res++; //res
        }

        if(fresh > 0)
            return -1;
        return res;

    }
};

 int main(){

    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<s.orangesRotting(grid);
    return 0;
 }