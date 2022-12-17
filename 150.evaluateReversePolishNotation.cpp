#include "header.hpp"
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<string> operators = {"+", "-", "*", "/"};
        stack<int64_t> operands;
        int i = 0;

        while (i < tokens.size())
        {
            // if it's an operand
            if (find(operators.begin(), operators.end(), tokens[i]) == operators.end())
            {
                operands.push(stoi(tokens[i]));
                i++;
            }
            else // it's an operator
            {
                int64_t op2 = operands.top();
                operands.pop();
                int64_t op1 = operands.top();
                operands.pop();
                int64_t res = 0;
                if (tokens[i] == "+")
                    res = op1 + op2;
                else if (tokens[i] == "-")
                    res = op1 - op2;
                else if (tokens[i] == "*")
                    res = op1 * op2;
                else
                    res = op1 / op2;

                operands.push(res);
                i++;
            }
        }

        return operands.top();
    }
};