#include "header.hpp"
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        set<pair<int, int>> lightPos;
        unordered_map<int, int> lightRow;
        unordered_map<int, int> lightCol;
        unordered_map<int, int> lightDiag;
        unordered_map<int, int> lightAnti;

        for (const auto &lamp : lamps)
        {
            if (lightPos.insert({lamp[0], lamp[1]}).second)
            {
                lightRow[lamp[0]]++;
                lightCol[lamp[1]]++;
                lightDiag[lamp[0] - lamp[1]]++;
                lightAnti[lamp[0] + lamp[1]]++;
            }
        }

        vector<int> res;
        for (const auto &query : queries)
        {
            // if there's a light
            if (lightRow[query[0]] || lightCol[query[1]] || lightDiag[query[0] - query[1]] || lightAnti[query[0] + query[1]])
                res.push_back(1);
            else
                res.push_back(0);

            // update the lamp state
            for (int adj_x = query[0] - 1; adj_x <= query[0] + 1; adj_x++)
            {
                for (int adj_y = query[1] - 1; adj_y <= query[1] + 1; adj_y++)
                {
                    if (lightPos.erase({adj_x, adj_y}))
                    {
                        lightRow[adj_x]--;
                        lightCol[adj_y]--;
                        lightDiag[adj_x - adj_y]--;
                        lightAnti[adj_x + adj_y]--;
                    }
                }
            }
        }

        return res;
    }
};