#include "header.hpp"
//brute Force
class SolutionBF
{
public:
    int findKthNumber(int m, int n, int k)
    {
        vector<int> memory;
        for (int i = 0; i < m; m++)
        {
            for (int j = 0; j < n; j++)
            {
                memory.push_back(i * j);
            }
        }

        sort(memory.begin(), memory.end());

        return memory[k - 1];
    }
};

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        }
};