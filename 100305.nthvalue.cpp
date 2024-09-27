#include "header.hpp"
// You are given two integers n and k.

// Initially, you start with an array a of n integers where a[i] = 1 for all 0 <= i <= n - 1. After each second, you simultaneously update each element to be the sum of all its preceding elements plus the element itself. For example, after one second, a[0] remains the same, a[1] becomes a[0] + a[1], a[2] becomes a[0] + a[1] + a[2], and so on.

// Return the value of a[n - 1] after k seconds.


class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int64_t> a(n, 1);
        for(int i = 0; i < k; i++){
            for(int j = 1; j < n; j++){
                a[j] += a[j-1];
            }
        }
        return a[n-1]%1000000007;
        
    }
};