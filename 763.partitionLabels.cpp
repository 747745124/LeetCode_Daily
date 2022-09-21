#include "header.hpp"
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, pair<int, int>> presence;
        for (int i = 0; i < s.size(); i++)
        {
            // haven't present before
            if (presence.count(s[i]) == 0)
            {

                presence[s[i]].first = i;
                presence[s[i]].second = i;
            }
            // if has been present before, update the last time it present
            else
                presence[s[i]].second = i;
        }

        vector<pair<int, int>> interval;
        vector<vector<int>> merged;

        for (const auto &kv : presence)
        {
            interval.push_back(kv.second);
        }

        sort(interval.begin(), interval.end());

        for (const auto &itv : interval)
        {
            int firstPres = itv.first;
            int lastPres = itv.second;
            if (merged.empty() || merged.back()[1] < firstPres)
                merged.push_back(vector<int>{firstPres, lastPres});
            else
            {
                merged.back()[1] = max(lastPres, merged.back()[1]);
            }
        }

        vector<int> res;
        for (const auto &intervals : merged)
        {
            res.push_back(intervals[1] - intervals[0] + 1);
        }
        return res;
    }

    vector<int> partitionLabels(string s)
    {
        unordered_map<char, pair<int, int>> presences;
        // char, span
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (presences.count(ch) == 0)
            {
                presences[ch] = std::make_pair(i, i);
            }
            else
            {
                presences[ch].second = i;
            }
        }

        vector<pair<int, int>> interval;
        vector<vector<int>> merged;

        for (const auto &kv : presences)
        {
            interval.push_back(kv.second);
        }

        sort(interval.begin(), interval.end());

        for (const auto &itv : interval)
        {
            int firstPres = itv.first;
            int lastPres = itv.second;
            if (merged.empty() || merged.back()[1] < firstPres)
                merged.push_back(vector<int>{firstPres, lastPres});
            else
            {
                merged.back()[1] = max(lastPres, merged.back()[1]);
            }
        }

        vector<int> res;
        for (const auto &intervals : merged)
        {
            res.push_back(intervals[1] - intervals[0] + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> res = s.partitionLabels(s1);
    for (const auto &i : res)
        cout << i << " ";
    cout << endl;
}