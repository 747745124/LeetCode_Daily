#include "header.hpp"
class LRUCache
{
private:
    vector<int> cache;

public:
    LRUCache(int capacity)
    {
        cache.resize(capacity + 1);
        for (int i = 0; i < capacity + 1; i++)
        {
            cache[i] = -1;
        }
    }

    int get(int key)
    {
        int idx = cache[key];
        if (idx == -1)
        {
            return -1;
        }
        else
        {
            int val = cache[idx];
            cache[key] = idx;
            cache[idx] = key;
            return val;
        }
    }

    void put(int key, int value)
    {
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */