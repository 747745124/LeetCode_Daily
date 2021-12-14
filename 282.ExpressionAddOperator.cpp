//check expression contains leading zero
// def isValid(self, expr):
//     elemList = re.findall(r"[\w']+", expr)
//     for elem in elemList:
//         if(elem.startswith('0') and len(elem) > 1):
//             return False
//     return True

// def addOperatorsBFCleansed(self, num, target):
//     combo = list(product(ops, repeat=len(num)-1))
//     resList = []
//     for opl in combo:
//         newNum = num
//         for idx in range(len(opl)).__reversed__():
//             '''check cases for leading zero'''
//             idx += 1
//             if(((newNum[idx:][0] == '0') and len(newNum[idx:]) > 1) and newNum[idx:].isdigit()):
//                 break
//             newNum = newNum[:idx] + opl[idx-1] + newNum[idx:]

//         if(not self.isValid(newNum)):
//             continue

//         if newNum.isdigit():
//             if newNum[0] == '0':
//                 continue

//         if eval(newNum) == target:
//             resList.append(newNum)

//     return resList
#include <iterator>
#include <utility>
#include <tuple>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctype.h>
using namespace std;

class Solution
{
public:
    vector<string> ops{"+", "-", "*", ""};
    bool isNumber(const string &str)
    {
        for (char const &c : str)
        {
            if (std::isdigit(c) == 0)
                return false;
        }
        return true;
    }
    bool isValid(const string &expr)
    {
        vector<string> elemList;
        std::string const delims{"+-*\0"};
        size_t beg, pos = 0;
        while ((beg = expr.find_first_not_of(delims, pos)) != std::string::npos)
        {
            pos = expr.find_first_of(delims, beg + 1);
            elemList.push_back(expr.substr(beg, pos - beg));
        }

        for (const auto &elem : elemList)
            if (elem[0] == '0' && elem.size() > 1)
                return false;

        return true;
    }

    vector<std::vector<string> > product(const std::vector<std::vector<string> > &lists)
    {
        std::vector<std::vector<string> > result;
        if (std::find_if(begin(lists), end(lists),
                         [](auto e) -> bool
                         { return e.size() == 0; }) != end(lists))
        {
            return result;
        }
        for (auto &e : lists[0])
        {
            result.push_back({e});
        }
        for (size_t i = 1; i < lists.size(); ++i)
        {
            std::vector<std::vector<string> > temp;
            for (auto &e : result)
            {
                for (auto f : lists[i])
                {
                    auto e_tmp = e;
                    e_tmp.push_back(f);
                    temp.push_back(e_tmp);
                }
            }
            result = temp;
        }
        return result;
    }

    map<string, int> op_mapping;  // 运算符优先级映射表
    string opss = "+-*/()";       // 包含所有运算符的字符串，为了通过find方法快速判断目标字符是否为操作符
    bool ValueError = false;      // 是否发生数值错误的标记
    bool ExpressionError = false; // 是否发生表达式错误的标记

    // 将string转换成double
    double toDouble(string str)
    {
        double target;
        stringstream ss;
        ss << str;
        ss >> target;
        return target;
    }

    // 初始化操作符优先级映射表
    void init_mapping(map<string, int> &mapping)
    {
        mapping["+"] = 0;
        mapping["-"] = 0;
        mapping["*"] = 1;
        mapping["/"] = 1;
        mapping["("] = 2;
        mapping[")"] = 2;
    }

    // 将中缀表达式转化为后缀表达式
    vector<string> toPostfix(string formula)
    {
        vector<string> result;
        vector<string> op_stack;
        string cur_num, cur_op;

        for (int i = 0; i < formula.size(); ++i)
        {
            if (opss.find(formula[i]) == opss.npos) // 扫描到的是操作数
                cur_num += formula[i];

            else // 扫描到的是操作符，现将累加的操作数字符串加入
            {
                if (!cur_num.empty())
                {
                    result.push_back(cur_num);
                    cur_num.clear();
                }

                cur_op = formula[i];

                if (op_stack.empty()) // 栈为空，直接入栈
                    op_stack.push_back(cur_op);
                else if (cur_op == "(") // 当前操作数为左括号，直接入栈
                    op_stack.push_back(cur_op);
                else if (cur_op == ")") // 当前操作数为右括号，则需要将op_stack中直到左括号前的所有的元素弹出
                {
                    while (op_stack.back() != "(")
                    {
                        result.push_back(op_stack.back());
                        op_stack.pop_back();

                        if (op_stack.empty()) // 不合法的表达式会出现这样的情况
                        {
                            ExpressionError = true;
                            result.push_back("0");
                            return result;
                        }
                    }
                    op_stack.pop_back(); // 将左括号弹出
                }
                else if (op_stack.back() == "(") // 在当前操作符不是括号的情况下，如果栈顶元素为左括号，则直接入栈
                    op_stack.push_back(cur_op);
                else if (op_mapping[cur_op] > op_mapping[op_stack.back()]) // 在当前操作符和栈顶元素为+-*/的情况下，若当前操作符优先级大于栈顶元素，直接入栈
                    op_stack.push_back(cur_op);
                else // 最后一种情况就是当前操作符的优先级低于或等于栈顶元素优先级时
                {
                    while ((op_stack.back() != "(") && (op_mapping[op_stack.back()] >= op_mapping[cur_op]))
                    {
                        result.push_back(op_stack.back());
                        op_stack.pop_back();
                        // 若栈已空，则直接返回
                        if (op_stack.empty())
                            break;
                    }
                    op_stack.push_back(cur_op); // 符合要求的操作符弹出后，当前操作符入栈
                }
            }
        }

        result.push_back(cur_num);

        // 最后op_stack可能还会有剩余元素，全部弹出
        while (!op_stack.empty())
        {
            result.push_back(op_stack.back());
            op_stack.pop_back();
        }

        return result;
    }

    double calculatePostfix(vector<string> &postfix)
    {
        vector<double> result;
        for (int i = 0; i < postfix.size(); ++i)
        {
            if (opss.find(postfix[i]) == opss.npos) // 扫描到操作数，直接压入栈中
                result.push_back(toDouble(postfix[i]));
            else // 扫描到操作符
            {
                // 如果剩余元素的数量小于2，则表达式非法
                if (result.size() < 2)
                {
                    ExpressionError = true;
                    return 0.0;
                }
                double num1 = result.back();
                result.pop_back();
                double num2 = result.back();
                result.pop_back();
                double op_res;
                // 分类讨论，计算num2 op num1
                if (postfix[i] == "+")
                    op_res = num2 + num1;
                else if (postfix[i] == "-")
                    op_res = num2 - num1;
                else if (postfix[i] == "*")
                    op_res = num2 * num1;
                else if (postfix[i] == "/")
                {
                    // 此处需要判断一下是否分母为0
                    if (num1 == 0)
                    {
                        ValueError = true;
                        return 0.0;
                    }

                    op_res = num2 / num1;
                }
                // 将所的结果重新压入栈中
                result.push_back(op_res);
            }
        }
        if (result.size() == 1) // 返回栈顶元素（如果是合法的表达式，则此时栈中只有一个元素）
            return result.back();
        else // 不合法的表达式会导致结束时，result中有不止一个元素
        {
            ExpressionError = true;
            return 0.0;
        }
    }

    double eval(string &infix)
    {
        vector<string> postfix = toPostfix(infix);
        return calculatePostfix(postfix);
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        int len = num.size() - 1;
        vector<vector<string> > lists;
        for (int i = 0; i < len; ++i)
            lists.push_back(ops);

        auto combo = product(lists);

        for (auto &op : combo)
        {
            auto newNum = num;

            for (auto i = op.size() - 1; i > 0; i--)
            {
                i++;
                if (((newNum.substr(i + 1)[0] == '0') and newNum.substr(i + 1).size() > 1) and isNumber(newNum.substr(i + 1)))
                    break;
                newNum = newNum.substr(0, i) + op[i - 1] + newNum.substr(i + 1);
            }

            if (!isValid(newNum))
                continue;

            if (isNumber(newNum))
            {
                if (newNum[0] == '0')
                    continue;
            }

            if (int(eval(newNum)) == target)
                res.push_back(newNum);
        }
        return res;
    }
};

int main()
{
    Solution s;
    // cout << s.isValid("0*223+2");
    vector<string> res = s.addOperators("123456789", 45);
    for (auto const &expr : res)
        cout << expr << std::endl;
    return 0;
}