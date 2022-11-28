#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_set<int> zeros, ones, mores; // lose 0, -1, -2
        for (const auto &match : matches)
        {
            int winner = match[0];
            int loser = match[1];

            if (!(ones.find(winner) != ones.end()) || mores.find(winner) != mores.end())
            {
                zeros.insert(winner);
            }

            if (zeros.find(loser) != zeros.end())
            {
                ones.insert(loser);
                zeros.erase(loser);
            }
            else if (ones.find(loser) != ones.end())
            {
                ones.erase(loser);
                mores.insert(loser);
            }
            else if (mores.find(loser) != mores.end())
            {
                continue;
            }
            else
            {
                ones.insert(loser);
            }
        }

        vector<int> all_winners = vector<int>(zeros.begin(), zeros.end());
        sort(all_winners.begin(), all_winners.end());
        vector<int> one_losers = vector<int>(ones.begin(), ones.end());
        sort(one_losers.begin(), one_losers.end());
        return {all_winners, one_losers};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matches = {{2, 3}, {1, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {4, 9}};
    auto res = s.findWinners(matches);
    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}