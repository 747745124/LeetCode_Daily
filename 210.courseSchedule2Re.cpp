#include "header.hpp"
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;
        vector<int> indegree;
        for(int i = 0; i< numCourses; i++){
            graph.push_back(vector<int>());
            indegree.push_back(0);
        }


        for(auto& edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto& neighbor : graph[curr]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        if(res.size() != numCourses){
            return vector<int>();
        }

        return res;
    }
};