#include "header.hpp"

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<point> points;
        vector<vector<int>> res;
        for (auto &bldg : buildings)
        {
            points.push_back(point(bldg[0], bldg[2], true));
            points.push_back(point(bldg[1], bldg[2], false));
        }
        // sort them by x
        sort(points.begin(), points.end(), [](point a, point b)

             {
            if (a.x == b.x && a.enter && b.enter)
            { // same entering, process highest
                return a.height > b.height;
            }
            if (a.x == b.x && !a.enter && !b.enter)
            { // same leaving, process lowest
                return a.height < b.height;
            }

                if (a.x == b.x)
                    return a.enter > b.enter; // process enter first
                return a.x < b.x; });

        multiset<int> pq;
        pq.insert(0);

        for (const auto &p : points)
        {
            if (p.enter)
            {
                if (p.height > *pq.rbegin())
                    res.push_back({p.x, p.height});
                pq.insert(p.height);
            }
            else
            {
                pq.erase(pq.find(p.height));
                if (p.height > *pq.rbegin())
                    res.push_back({p.x, *pq.rbegin()});
            }
        }

        return res;
    }

private:
    struct point
    {
        int x;
        int height;
        bool enter;
        point(int x, int height, bool enter) : x(x), height(height), enter(enter){};
    };
};

int main()
{
    Solution s;
    vector<vector<int>> buildings{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    s.getSkyline(buildings);
}