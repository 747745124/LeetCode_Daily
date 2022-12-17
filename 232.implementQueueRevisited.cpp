#include "header.hpp"
class MyQueue
{
public:
    stack<int> stk_in, stk_out;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!stk_out.empty())
        {
            stk_in.push(stk_out.top());
            stk_out.pop();
        }
        stk_in.push(x);
    }

    int pop()
    {
        while (!stk_in.empty())
        {
            stk_out.push(stk_in.top());
            stk_in.pop();
        }
        int res = stk_out.top();
        stk_out.pop();
        return res;
    }

    int peek()
    {
        while (!stk_in.empty())
        {
            stk_out.push(stk_in.top());
            stk_in.pop();
        }
        return stk_out.top();
    }

    bool empty()
    {
        return stk_in.empty() && stk_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */