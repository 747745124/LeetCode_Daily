#include "header.hpp"


vector<vector<int>> dfs(int vertex, int parent, int distance, const vector<vector<int>>& graph, int& maxDistance, int& maxVertex){
    //starting from the vertex, we will traverse the graph
    maxVertex = vertex;
    maxDistance = distance;
    vector<vector<int>> maxPaths = {{vertex}};

    for(const auto& adj : graph[vertex]){
        if(adj == parent)
            continue;
        
        int childMaxDistance;
        int childMaxVertex;
        vector<vector<int>> childMaxPaths = dfs(adj,vertex,distance+1,graph, childMaxDistance, childMaxVertex);

        if(childMaxDistance > maxDistance){
            maxDistance = childMaxDistance;
            maxVertex = childMaxVertex;
            //update the maxPaths
            maxPaths.clear();

            maxPaths = childMaxPaths;   
        }
        }
        //if the child has the same distance as the maxDistance, we will add the path to the maxPaths
        else if(childMaxDistance == maxDistance){
            
        }
            
    }

    return maxPaths;

}



int main(){
    vector<int> g_from = {1,1,2};
    vector<int> g_to = {2,3,4};
    int n = 4;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < g_from.size(); i++){
        graph[g_from[i]].push_back(g_to[i]);
        graph[g_to[i]].push_back(g_from[i]);
    }

    int _, _maxVertex = 0;
    auto paths = dfs(1,0,0,graph, _, _maxVertex);
    auto maxPaths = dfs(_maxVertex, 0, 0, graph, _, _maxVertex);

    for(const auto& path : maxPaths){
        for(const auto& vertex : path){
            cout << vertex << ' ';
        }
        cout << endl;
    }
}