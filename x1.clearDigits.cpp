#include "header.hpp"
//You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.
class Solution {
public:
    string clearDigits(string s) {
        string res = s;
        vector<int> alphaPos;


        for(int i=0;i<s.size();i++) {
            auto ch = s[i];
            if(isalpha(ch)){
                alphaPos.push_back(i);
            }
            else{
                if(alphaPos.size() > 0){
                    res[i] = ' ';
                    res[alphaPos.back()] = ' ';
                    alphaPos.pop_back();
                }
            }

        }

        // remove   extra spaces
        string ans = "";
        for(int i=0;i<res.size();i++){
            if(res[i] != ' ') ans += res[i];
        }

        return ans;
        
    }
};

int main(){
    Solution s;
    cout << s.clearDigits("ab1234cd") << endl;
    cout << s.clearDigits("ab1234cd1234") << endl;
    cout << s.clearDigits("1234abcd") << endl;
    cout << s.clearDigits("1234abcd1234") << endl;
    cout << s.clearDigits("abcd") << endl;
    cout << s.clearDigits("a8f") << endl;

}