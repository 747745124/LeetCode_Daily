#include "header.hpp"
class Solution {
public:
    string getEncryptedString(string s, int k) {
        //shift the string by k steps
        int n = s.size();
        int k = k%n;
        string res = s.substr(k) + s.substr(0, k);
    }
};