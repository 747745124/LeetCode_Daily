#include "header.hpp"
class Solution {
public:

    int passThePillow(int n, int time) {

        int rounds = (time)/(n-1);
        int excess = time - (n-1)*rounds;

        if(rounds%2==0)
            return excess+1;
        
        return n-excess;

    }
};
