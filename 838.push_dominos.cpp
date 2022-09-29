#include "header.hpp"

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        // extract the symbols, making it a position, symbol pair
        vector<pair<int, char>> symbols;
        symbols.push_back(make_pair(-1, 'L'));
        for (int i = 0; i < dominoes.size(); i++)
        {
            if (dominoes[i] == 'L' || dominoes[i] == 'R')
                symbols.push_back(std::make_pair(i, dominoes[i]));
        }
        symbols.push_back(make_pair(dominoes.size(), 'R'));

        for (int i = 0; i < symbols.size() - 1; i++)
        {
            auto &first = symbols[i];
            auto &second = symbols[i + 1];

            if (first.second == second.second) // LL or LR
            {
                for (int i = first.first + 1; i < second.first; i++)
                    dominoes[i] = first.second;
            }
            else if (first.second == 'R' && second.second == 'L') // R...
            {
                for (int i = 0; i < (second.first - first.first - 1) / 2; i++)
                {
                    dominoes[first.first + i + 1] = 'R';
                    dominoes[second.first - i - 1] = 'L';
                }
            }
        }

        return dominoes;
    }
};

int main()
{
    Solution solution;
    cout << solution.pushDominoes(".L.R...LR..L..") << endl;
}