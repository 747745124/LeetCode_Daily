#include "header.hpp"
class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        // intuition, do the instructions 4 times
        // if the robot is in the same place, it is bounded
        // otherwise, it is not bounded

        int x = 0, y = 0, dir = 0;

        for (int i = 0; i < 4; i++)
        {
            for (auto &c : instructions)
            {
                if (c == 'G')
                {
                    if (dir == 0)
                        y++;
                    else if (dir == 1)
                        x++;
                    else if (dir == 2)
                        y--;
                    else
                        x--;
                }
                // turn left
                else if (c == 'L')
                    dir = (dir + 1) % 4;
                // turn right
                else
                    dir = (dir + 3) % 4;
            }
            if (x == 0 && y == 0)
                return true;
        }
        return x == 0 && y == 0;
    }
};

int main()
{
    Solution solution;
    cout << solution.isRobotBounded("GGLLGG") << endl;
    return 0;
}