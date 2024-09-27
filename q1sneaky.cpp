#include "header.hpp"
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,bool> isPresent(nums.size());
        vector<int> res;

        for(int i = 0; i < nums.size();i++) {
            if(isPresent[nums[i]]==false)
                isPresent[nums[i]]==true;
            else
                res.push_back(nums[i]);
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    vector<int> res = s.getSneakyNumbers(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}