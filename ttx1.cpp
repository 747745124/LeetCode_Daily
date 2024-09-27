#include "header.hpp"

int getBestDeal(vector<int>&prices,int k){

    auto sum = std::reduce(prices.begin(), prices.end());

    make_heap(prices.begin(),prices.end());
    int res = 0;

    for(int i=0;i<k;i++){
        res += prices[0]/2;
        prices[0] /=2;
        make_heap(prices.begin(),prices.end());
    }

    return sum-res;

}

int main(){

//     vouchersCount = 3
// prices = [8, 2, 13]


    vector<int> prices = {8,2,13};
    int k = 3;
    cout<<getBestDeal(prices,k)<<endl;
    return 0;
}