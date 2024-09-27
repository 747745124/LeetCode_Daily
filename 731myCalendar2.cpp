#include "header.hpp"
class MyCalendarTwo {
public:

    MyCalendarTwo() {
        sweeper = {};
    }
    
    bool book(int start, int end) {
        sweeper[start]++;
        sweeper[end]--;
        int count = 0;
        for(const auto&kv:sweeper) {
            count+=kv.second;
            if(count>=3)
            {
                sweeper[start]--;
                sweeper[end]++;
                return false;
            }
            
            if(kv.first>end)
                break;
        }

        return true;
    }

    

private:
    map<int,int> sweeper;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */