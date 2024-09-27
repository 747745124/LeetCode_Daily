#include "header.hpp"

int longestMarathon(vector<int> runtime){
    sort(runtime.begin(), runtime.end());

    int maxLength = 1;
    int currLength = 1;

    for (int i = 1; i < runtime.size();i++){
        if(runtime[i] == runtime[i - 1] || 
            runtime[i] == runtime[i - 1] + 1)
            currLength++; //

    }

};

int main(){

}