#include "header.hpp"
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //always go for the one with higher points first
        bool larger = x > y;
        int res = 0;

        stack<char> stk;

        for(const auto& ch : s) {

            bool case_1 = (!stk.empty())&&(stk.top()=='a'&& ch=='b');
            bool case_2 = (!stk.empty())&&(stk.top()=='b'&& ch=='a');

            //2 pass, first pass do the larger, second pass do the smaller
            if (larger){
                
                //do all larger strings
                if(stk.empty() || !(case_1)){
                    stk.push(ch);
                }
                else if(!stk.empty()&&case_1)
                {
                    stk.pop();
                    res += x;
                }
                
            }else{
                //do all larger strings
                if(stk.empty() || !(case_2)){
                    stk.push(ch);
                }
                else if(!stk.empty()&&case_2){
                    stk.pop();
                    res+=y;
                }
                

            }

        }

        //get the string
        string str = "";
        while(!stk.empty()){
            str+=stk.top();
            stk.pop();
        }

        reverse(str.begin(),str.end());

        for(const auto& ch : str) {

            bool case_1 = (!stk.empty())&&(stk.top()=='a'&& ch=='b');
            bool case_2 = (!stk.empty())&&(stk.top()=='b'&& ch=='a');

            //2 pass, first pass do the larger, second pass do the smaller
            if (larger){
                
                //do all smaller strings
                if(stk.empty() || !(case_2)){
                    stk.push(ch);
                }
                else{
                    if(!stk.empty()&&case_2){
                        stk.pop();
                        res += y;
                    }
                }

            }else{
                //do all larger strings
                if(stk.empty() || !(case_1)){
                    stk.push(ch);
                }
                else{
                    if(!stk.empty()&&case_1){
                        stk.pop();
                        res+=x;
                    }
                }

            }

        }

        return res;


    }
};

int main(){
    Solution s;
    cout<<s.maximumGain("cdbcbbaaabab",4,5);
}