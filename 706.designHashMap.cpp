#include "header.hpp"
class MyHashMap
{
public:
    MyHashMap()
    {
        vector<int> keys;
        vector<int> values;
    }

    void put(int key, int value)
    {
        auto it = find(keys.begin(), keys.end(), key);

        if (it == keys.end())
        {
            keys.push_back(key);
            values.push_back(value);
            return;
        }

        auto idx = it - keys.begin();
        values[idx] = value;
    }

    int get(int key)
    {
        auto it = find(keys.begin(), keys.end(), key);
        if (it == keys.end())
            return -1;
        auto idx = it - keys.begin();
        return values[idx];
    }

    void remove(int key)
    {
        auto it = find(keys.begin(), keys.end(), key);
        if (it == keys.end())
            return;
        auto idx = it - keys.begin();
        return values.erase(idx);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */