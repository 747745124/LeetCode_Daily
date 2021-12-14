#include "header.hpp"
class MyQueue
{
public:
    stack<int> inStack;
    stack<int> outStack;
    MyQueue()
    {
    }

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        while (!inStack.empty())
        {
            outStack.push(inStack.pop());
        }

        outStack.pop();
    }

    int peek()
    {
        while (!inStack.empty())
        {
            outStack.push(inStack.pop());
        }

        outStack.top();
    }

    bool empty()
    {
        if (inStack.empty() && outStack.empty())
            return true;
        return false;
    }
};