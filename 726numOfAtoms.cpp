#include "header.hpp"
class Solution {
public:
    void mult_map(unordered_map<string,int>&map,int multiplier){
        for(auto&kv:map){
            kv.second *= multiplier;
        }
    }

    void add_map(unordered_map<string,int>&map1,unordered_map<string,int>&map2){
        // add to map 1
        for(auto&kv:map2){
            if(map1.count(kv.first))
                map1[kv.first] += kv.second;
            else
                map1[kv.first] = kv.second;
        }
    }

    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>> stk;
        unordered_map<string,int> freq;
        string res;

        for(int i = 0;i<formula.size();i++){
            char ch = formula[i];

            if(ch=='(')
            {
                stk.push({});
                continue;
            }

            if(ch==')')
            {
                string num = "";
                int multiplier = 1;
                i++;

                while(i<formula.size()&&isnumber(formula[i])){
                //get the number
                    num += formula[i];
                    i++;
                }

                multiplier = stoi(num);
                auto f = stk.top();
                mult_map(f,multiplier);
                stk.pop();

                if(!stk.empty())
                    add_map(stk.top(),f);
                else
                    stk.push(f);

                i--;
                continue;
            }

            //if it's a letter and stack is empty
            if(stk.empty())
            {
                stk.push({});
            }

            //find out the element and count
            string num = "";
            string elem = string(1,ch);
            int multiplier = 1;
            i++;

            //right next to a number
            if(i<formula.size()&&isnumber(formula[i]))
            {
                while(i<formula.size()&&isnumber(formula[i])){
                    num+=formula[i];
                    i++;
                }
                if(num!="")
                    multiplier = stoi(num);
                auto& f = stk.top();
                f[elem] += multiplier;

                i--;
                continue;
            }

            //right next to a lower case
            if(i<formula.size()&&islower(formula[i]))
            {
                elem += formula[i];
                i++;

                while(i<formula.size()&&isnumber(formula[i])){
                    num+=formula[i];
                    i++;
                }

                if(num!="")
                    multiplier = stoi(num);

                auto& f = stk.top();
                f[elem] += multiplier;

                i--;
                continue;
            }

            //right next to another upper case
            auto& f = stk.top();
            f[elem] += 1;
            i--;
        }

        auto& f = stk.top();
        map<string,int> m;

        for(const auto& kv:f){
            m[kv.first] = kv.second;
        }

        for(const auto& kv:m){
            res += kv.first;
            if(kv.second!=1)
                res += to_string(kv.second);
        }
        
        return res;
    }
};

int main(){
    Solution solution;
    cout<<solution.countOfAtoms("K4(ON(SO3)2)2");
}

