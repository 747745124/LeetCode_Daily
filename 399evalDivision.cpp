#include "header.hpp"
class Solution {
    using Graph = unordered_map<string,vector<pair<string,double>>>;
    unordered_map<string,bool> isVisited;

private:
    bool findDistance(Graph&graph,const string curr,const string dst, double& distance){
        if(curr == dst) 
        {   
            distance *= 1.0;
            return true;
        }

        isVisited[curr] = true;
        for(const auto&child : graph[curr]){
            if(!isVisited[child.first])
            {   
                distance *= child.second;
                if(findDistance(graph,child.first, dst, distance))
                    return true;
                distance /= child.second;
            }
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Graph graph;
        vector<double> res;
        for(int i = 0; i < equations.size();i++){
            auto equation = equations[i];
            graph[equation[0]].push_back(make_pair(equation[1],values[i]));
            graph[equation[1]].push_back(make_pair(equation[0],1.0/values[i]));
        }

        for(int i = 0; i < queries.size();i++){
            auto query = queries[i];
            double result = 1.0;

            for(const auto&kv:graph){
                isVisited[kv.first]=false;
            }

            if(!graph.count(query[0])||!graph.count(query[1]))
                res.push_back(-1.0);
            else
            {   
                findDistance(graph,query[0],query[1],result);
                if(!isVisited[query[1]])
                    res.push_back(-1.0);
                else
                    res.push_back(result);
            }
        }

        return res;
    }
    
};

int main(){

    Solution s;
// equations =
// [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
// values =
// [3.0,4.0,5.0,6.0]
// queries =
// [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]

    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    vector<double> values = {3.0,4.0,5.0,6.0};
    vector<vector<string>> queries = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};

    vector<double> res = s.calcEquation(equations,values,queries);
    return 0;
}