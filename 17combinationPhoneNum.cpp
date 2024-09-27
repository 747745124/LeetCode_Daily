#include "header.hpp"
class Solution {
public:
    std::unordered_map<char,vector<char>> numToAlpha;
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        vector<string> result;
        
        numToAlpha['2'] = {'a','b','c'};
        numToAlpha['3'] = {'d','e','f'};
        numToAlpha['4'] = {'g','h','i'};
        numToAlpha['5'] = {'j','k','l'};
        numToAlpha['6'] = {'m','n','o'};
        numToAlpha['7'] = {'p','q','r','s'};
        numToAlpha['8'] = {'t','u','v'};
        numToAlpha['9'] = {'w','x','y','z'};

        for(const auto& ch:numToAlpha[digits[0]]){
            result.push_back(string(1,ch));
        }

        return getCombinations(digits.substr(1,digits.size()),result);
    }

    vector<string> getCombinations(string digits, vector<string> result) {
        if (digits.size() == 0) return result;

        const auto& num = digits[0];
        vector<string> next = {};

        for(int i = 0; i < result.size(); i++) {
            const auto str = result[i];
            //enumerate all possible char, add to the current result
            for(const auto& ch:numToAlpha[num]){
                next.push_back(str+ch);
            }
        }

        return getCombinations(digits.substr(1,digits.size()), next);
    }
};

int main(){
    Solution s;
    vector<string> result = s.letterCombinations("23");
    
    for(const auto& str:result){
        cout << str << endl;
    }

    return 0;
}