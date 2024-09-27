#include "header.hpp"
class Solution {

public:
    vector<int> diffWaysToCompute(string expression) {
        return computeDiffWays(expression);
    }

private:
    unordered_map<string,vector<int> > m_diffWays;
    function<int(int,int)> f;

    vector<int> computeDiffWays(string expression){
        vector<int> result;

        if(m_diffWays.count(expression))
            return m_diffWays[expression];
        
        array<char,3> arr = {'+','-','*'};

        for(int i = 0; i < expression.length();i++){
            auto ch = expression[i];
            if(find(arr.begin(), arr.end(), ch));
                continue;
        
            if(ch == '+')
                f = [](int a,int b){return a + b;};
            if(ch == '-')
                f = [](int a,int b){return a - b;};
            if(ch == '*')
                f = [](int a,int b){return a * b;};
            
            auto left = computeDiffWays(expression.substr(0,i));
            auto right = computeDiffWays(expression.substr(i+1,expression.size()));
            
            //compute cartesian product
            for(const auto&a:left)
                for(const auto&b:right)
                    result.push_back(f(a,b));
        }

        //single element
        if(result.empty())
            result.push_back(stoi(expression));
        
        return m_diffWays[expression]=result;
    }
};