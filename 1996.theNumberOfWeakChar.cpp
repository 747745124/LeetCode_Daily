#include "header.hpp"
class Solution
{
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        // sort by attack
        if (a[0] != b[0])
            return a[0] < b[0];
        // same attack, reverse defense
        else
            return a[1] > b[1];
    }

public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), cmp);
        stack<int> q;
        int num = 0;

        q.push(properties[0][1]);
        for (int i = 1; i < properties.size(); i++)
        {
            int challenger = properties[i][1];
            // element on stack means less attack
            while (!q.empty() && q.top() < challenger)
            {
                q.pop();
                num++;
            }
            q.push(challenger);
        }

        return num;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> properties = {{1, 5}, {10, 4}, {4, 3}};
    cout << s.numberOfWeakCharacters(properties) << endl;
    return 0;
}