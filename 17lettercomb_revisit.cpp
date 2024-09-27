#include "header.hpp"
class Solution {
public:
    std::unordered_map<char,vector<char>> numToAlpha;
    vector<string> results;
    string phoneDigits;
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        vector<string> result;

        phoneDigits = digits;
        
        numToAlpha['2'] = {'a','b','c'};
        numToAlpha['3'] = {'d','e','f'};
        numToAlpha['4'] = {'g','h','i'};
        numToAlpha['5'] = {'j','k','l'};
        numToAlpha['6'] = {'m','n','o'};
        numToAlpha['7'] = {'p','q','r','s'};
        numToAlpha['8'] = {'t','u','v'};
        numToAlpha['9'] = {'w','x','y','z'};

        getCombinations("",0);
        return results;
    }

    void getCombinations(string digit, int index) {
        if(digit.size()==phoneDigits.size())
            results.push_back(digit);
        
        for(const auto& ch: numToAlpha[phoneDigits[index]]){
            digit.push_back(ch);
            getCombinations(digit,index+1);
            digit.pop_back();
        }
    }
};