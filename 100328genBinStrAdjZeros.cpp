#include "header.hpp"
class Solution {
public:
    vector<string> validStrings(int n) {
        //a string with no consecutive 0
        vector<string> res;
        //generate all binary strings of length n
        string s = "";
        generateStrings(res, s, n);
        return res;
    }

    void generateStrings(vector<string>& res, string s, int n){
        if(s.size()==n){
            res.push_back(s);
            return;
        }

        if(s.size()==0 || s[s.size()-1]=='1'){
            generateStrings(res, s+'0', n);
            generateStrings(res, s+'1', n);
        }else{
            generateStrings(res, s+'1', n);
        }
    }
};