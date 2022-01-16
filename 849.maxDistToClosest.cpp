#include "header.hpp"
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int res = 0;
        int len = 0;
        // general case
        for (const auto &seat : seats)
        {
            if (seat == 1)
                len = 0;
            else
            {
                len++;
                res = max(res, (len + 1) / 2);
            }
        }
        // one side case, 00001, or 10000
        for (int i = 0; i < seats.size(); i++)
            if (seats[i] == 1)
            {
                res = max(res, i);
                break;
            }

        for (int i = seats.size() - 1; i >= 0; i--)
            if (seats[i] == 1)
            {
                res = max(res, int(seats.size()) - 1 - i);
                break;
            }

        return res;
    }
};