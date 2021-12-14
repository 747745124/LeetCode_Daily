/*
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string grid[3][3] = {"", "", "", "", "", "", "", "", ""};

    string tictactoe(vector<vector<int> > &moves)
    {

        for (int i = 0; i < moves.size(); i++)
        {
            if (i % 2 == 0)
                paintX(grid, moves[i]);
            else
                paintO(grid, moves[i]);
        }

        return isValid(grid);
        //check validity
    }

    void paintX(string (&grid)[3][3], const vector<int> &coord)
    {
        grid[coord[0]][coord[1]] = "X";
    }

    void paintO(string (&grid)[3][3], const vector<int> &coord)
    {
        grid[coord[0]][coord[1]] = "O";
    }

    string isValid(string (&grid)[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            auto row = grid[i];
            if (count(row, row + 3, "X") > 2)
                return "A";
            if (count(row, row + 3, "O") > 2)
                return "B";
        }

        for (int i = 0; i < 3; i++)
        {
            vector<string> col(3);
            col.push_back(grid[0][i]);
            col.push_back(grid[1][i]);
            col.push_back(grid[2][i]);
            if (count(col.begin(), col.end(), "X") > 2)
                return "A";
            if (count(col.begin(), col.end(), "O") > 2)
                return "B";
        }

        if (grid[0][0] == "X" && grid[1][1] == "X" && grid[2][2] == "X")
            return "A";
        if (grid[0][2] == "X" && grid[1][1] == "X" && grid[2][0] == "X")
            return "A";
        if (grid[0][0] == "O" && grid[1][1] == "O" && grid[2][2] == "O")
            return "B";
        if (grid[0][2] == "O" && grid[1][1] == "O" && grid[2][0] == "O")
            return "B";
        //if no empty,

        int count = 0;
        for (auto &row : grid)
            for (auto &elem : row)
            {
                if (elem == "")
                    count++;
            }

        if (count == 0)
            return "Draw";

        return "Pending";
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > moves;
    moves.push_back(vector<int>{0, 0});
    moves.push_back(vector<int>{1, 1});
    moves.push_back(vector<int>{0, 1});
    moves.push_back(vector<int>{0, 2});
    moves.push_back(vector<int>{1, 0});
    moves.push_back(vector<int>{2, 0});

    cout << solution.tictactoe(moves) << endl;
    auto Grid = solution.grid;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Grid[i][j] << " ";
        }
        cout << endl;
    }
}