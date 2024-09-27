#include "header.hpp"
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> m;
        for(int i=0; i<names.size(); i++)
        {
            m[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end(),std::greater());

        vector<string> res;
        for(const auto &h: heights)
        {
            res.push_back(m[h]);
        }

        return res;
    }
};