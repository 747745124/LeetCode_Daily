#include "header.hpp"

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> present(n, 0);
        for (const auto &num : nums)
        {
            if (!present[num - 1])
                present[num - 1] = 1;
            continue;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (present[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};

/*
Solution2:
Negate each element to its indexed negative, 
the positive ones are those left.
[1,2,2,4]
->[-1,-2,2,-4]
3 is left

if some value is i in the list, the position i should be negative

Such solutions are compatible with [1~n] to [1~n] mapping
*/