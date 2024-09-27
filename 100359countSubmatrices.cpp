#include "header.hpp"
// Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contains:

// grid[0][0]
// an equal frequency of 'X' and 'Y'.
// at least one 'X'.
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<pair<int, int> > > prefix(grid.size(), vector<pair<int, int> >(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) { 
            for (int j = 0; j < grid[0].size(); j++) {
                prefix[i][j] = {0, 0};
            }
        } 
        for (int i = 0; i < grid.size(); i++) { 
            for (int j = 0; j < grid[0].size(); j++) 
                prefix[i][j] = {grid[i][j] == 'X', grid[i][j] == 'Y'};
        } 
        for (int j = 1; j < grid[0].size(); j++)  {
            prefix[0][j].first += prefix[0][j-1].first;
            prefix[0][j].second += prefix[0][j-1].second;
        }
        for (int i = 1; i < grid.size(); i++)  {
            prefix[i][0].first += prefix[i-1][0].first;
            prefix[i][0].second += prefix[i-1][0].second;
        }
        for (int i = 1; i < grid.size(); i++) { 
            for (int j = 1; j < grid[0].size(); j++) {
                prefix[i][j].first += prefix[i - 1][j].first + prefix[i][j - 1].first - prefix[i - 1][j - 1].first; 
                prefix[i][j].second += prefix[i - 1][j].second + prefix[i][j - 1].second - prefix[i - 1][j - 1].second;
            }
        } 
        for (int i = 0; i < grid.size(); i++) { 
            for (int j = 0; j < grid[0].size(); j++) {
                if(prefix[i][j].first > 0 and prefix[i][j].second > 0 and prefix[i][j].first == prefix[i][j].second) ans++;
            }
        } 
        
        
        return ans;
    }
};