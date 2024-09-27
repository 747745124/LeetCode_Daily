#include "header.hpp"
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int index = 1;
        int x = 0;
        int y = 0;
        int maxDist = 0;

        for(const auto& command : commands){
            if(command==-2)
            {
                index = (index+3)%4;
            }

            else if(command==-1)
            {
                index = (index+1)%4;
            }

            else{
                int dx = dirs[index];
                int dy = dirs[index+1];
                bool isObstacle = false;
                for(const auto& obstacle : obstacles){
                    int o_x = obstacle[0];
                    int o_y = obstacle[1];

                    if(index==0)
                    {
                        if(o_y!=y)
                            continue;
                        if(o_x>=x)
                            continue;
                        if((x-o_x) > command)
                            continue;
                        
                        x = o_x+1;
                        isObstacle = true;
                        break;
                    }

                    if(index==1)
                    {
                        if(o_x!=x)
                            continue;
                        if(o_y<=y)
                            continue;
                        if((o_y-y) > command)
                            continue;
                        
                        y = o_y-1;
                        isObstacle = true;
                        break;
                    }

                    if(index==2)
                    {
                        if(o_y!=y)
                            continue;
                        if(o_x<=x)
                            continue;
                        if((o_x-x) > command)
                            continue;
                        
                        x = o_x-1;
                        isObstacle = true;
                        break;
                    }
                    
                    if(index==3)
                    {
                        if(o_x!=x)
                            continue;
                        if(o_y>=y)
                            continue;
                        if((y-o_y) > command)
                            continue;
                        
                        y = o_y+1;
                        isObstacle = true;
                        break;
                    }

                }

                if(!isObstacle)
                {
                    x += dx*command;
                    y += dy*command;
                }

                maxDist = max(maxDist,x*x+y*y);

            }
        };

       return maxDist;
    }
};