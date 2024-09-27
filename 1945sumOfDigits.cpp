#include "header.hpp"
class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";

        for(const auto&ch:s){
            num += to_string((ch-'a')+1);
        }

        for(int i=0; i<k-1; i++){
            num = to_string(sumDigits(num));
        };

        return sumDigits(num);
    }

private:
    int sumDigits(string s){
        int sum = 0;

        for(const auto&ch:s){
            sum += (ch-'0');
        }

        return sum;
    }
};