#include "header.hpp"


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        //map to store the cost of changing from one char to another
        unordered_map<char,unordered_map<char,long long>> graph;
        unordered_set<char> vertices;

        for(int i=0; i<cost.size(); i++){
            vertices.insert(original[i]);
            vertices.insert(changed[i]);

            if(graph.count(original[i]) == 0){
                graph[original[i]][changed[i]] = cost[i];
                continue;
            }

            if(graph[original[i]].count(changed[i]) == 0){
                graph[original[i]][changed[i]] = cost[i];
                continue;
            }

            graph[original[i]][changed[i]] = min(graph[original[i]][changed[i]],(long long)cost[i]);
        }

        unordered_map<char,unordered_map<char,long long>> weights;
        //initialize the weights
        for(char v:vertices){
            for(char u:vertices){
                //0 on the diagonal
                if(v == u){
                    weights[v][u] = 0;
                    continue;
                }
                
                //if there is no edge between the vertices, set the weight to infinity
                if(graph.count(v) == 0 || graph[v].count(u) == 0){
                    weights[v][u] = LLONG_MAX;
                    continue;
                }

                //set the weight to the cost of changing from v to u
                weights[v][u] = graph[v][u];
            }
        }
        
        //floyd warshall algorithm
        for(char k:vertices){
            for(char i:vertices){
                for(char j:vertices){
                    if(weights[i][k] == LLONG_MAX || weights[k][j] == LLONG_MAX){
                        continue;
                    }
                    weights[i][j] = min(weights[i][j],weights[i][k] + weights[k][j]);
                }
            }
        }

        long long res = 0;

        for(int i=0; i<source.size(); i++){
            //if the distance is infinity
            if(weights[source[i]][target[i]] == LLONG_MAX){
                return -1;
            }
            //or not found
            if(weights[source[i]].count(target[i]) == 0||weights.count(source[i]) == 0){    
                return -1;
            }

            res += weights[source[i]][target[i]];
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<char> original = {'a','b','c','b','a','d'};
    vector<char> changed = {'d','c','b','d','b','b'};
    vector<int> cost = {3,8,7,6,7,10};
    cout<<s.minimumCost("aabbddccbc","abbbaabaca",original,changed,cost)<<endl;
    return 0;
}