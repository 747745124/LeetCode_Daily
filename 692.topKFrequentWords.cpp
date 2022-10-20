#include "header.hpp"
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (auto &string : words)
        {
            freq[string]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (auto &kv : freq)
        {
            pq.push(make_pair(-kv.second, kv.first));
        }

        vector<string> res;

        for (int i = 0; i < k; i++)
        {
            auto [freq, str] = pq.top();
            pq.pop();
            res.push_back(str);
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    {
        vector<string> c;
        c.push_back("i");
        c.push_back("love");
        c.push_back("leetcode");
        c.push_back("i");
        c.push_back("love");
        c.push_back("coding");
        s.topKFrequent(c, 2);
    }
    return 0;
}