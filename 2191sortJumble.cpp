#include "header.hpp"
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,vector<int>> mapped;
        for(int num : nums){
            mapped[getMapping(mapping,num)].push_back(num);
        }

        vector<int> res;
        for(const auto&kv:mapped){
            for(const auto&v:kv.second)
                res.push_back(v);
        }

        return res;
    }

    int getMapping(vector<int>& mapping, int num){

        string num_s = to_string(num);
        string res_s = "";
        for(const auto& ch:num_s){
            res_s += to_string(mapping[ch - '0']);
        }

        return stoi(res_s);
    }
};

int main(){
    Solution s;
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    vector<int> res = s.sortJumbled(mapping,nums);
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}