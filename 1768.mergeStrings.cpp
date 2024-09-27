#include "header.hpp"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size_1 = word1.length();
        int size_2 = word2.length();
        int index = 0;

        string res = "";

        while(index < min(size_1,size_2)){
            res += word1[index];
            res += word2[index];
            index++;
        }

        if(size_1 < size_2)
            res+= word2.substr(index);
        else if(size_1 > size_2)
            res+= word1.substr(index);

        return res;
    }
};