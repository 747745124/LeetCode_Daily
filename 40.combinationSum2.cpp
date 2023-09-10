#include "header.hpp"
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> counter;
        for(const auto&candidate : candidates){
            counter[candidate]+=1;
        }

        std::vector<std::pair<int,int>> ctr(counter.begin(),counter.end());

        vector<vector<int>>res;
        vector<int> comb;

        solve(0, res, comb, ctr,target);

        return res;
    }

    void solve(int curr, vector<vector<int>>& res, vector<int>& comb, std::vector<std::pair<int,int>> ctr,int target){
        
        if(target == 0){
            res.push_back(comb);
            return;
        }

        if(target < 0)
            return;

        for(int i = curr; i<ctr.size(); i++){
            int num = ctr[i].first;
            int& freq = ctr[i].second;

            if(freq<=0)
                continue;

            target -= num;
            comb.push_back(num);
            freq--;


            solve(i,res,comb,ctr,target);

            target += num;
            comb.pop_back();
            freq++;
        }

        return;
    }

};

int main(){
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum2(candidates,target);
    for(auto& v : res){
        for(auto& i : v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}