#include "header.hpp"
class Solution {
public:
    int numberOfChild(int n, int k) {
        int index = 0;
        bool isReverse = false;
        for(int i = 0; i < k; i++){
            if(isReverse){
                index--;
                if(index == 0){
                    isReverse = false;
                }
            }
            else{
                index++;
                if(index == n-1){
                    isReverse = true;
                }
            }
        }

        return index;
    }
};