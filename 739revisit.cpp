#include "header.hpp"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> monoStack;

        for(int i = 0; i < n; i++) {
            
            while(!monoStack.empty()&&temperatures[monoStack.top()] < temperatures[i]){
                //if today is hotter than stack top
                int date = monoStack.top();
                monoStack.pop();
                result[date] = i - date;
            }

            monoStack.push(i);
        }


    }
};