#include "header.hpp"
// if it was full, delete the first added key

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        lru = new ListNodeD(-1, -1);
        mru = new ListNodeD(-1, -1);
        lru->next = mru; // lru next->lru node
        mru->prev = lru; // mru prev-> mru node
    }

    int get(int key)
    {
        if (map.count(key))
        {
            auto node = map[key];

            // update priority
            remove(node);
            addToRight(node);

            return node->val.second;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (map.count(key)) // find
        {
            auto node = map[key];
            remove(node);
            // update val
            node->val.second = value;
            addToRight(node);
        }
        else if ((capacity - size) >= 1) // don't drop
        {
            auto node = new ListNodeD(key, value);
            map[key] = node;
            addToRight(node);
        }
        else // exceeded, drop
        {
            auto node = new ListNodeD(key, value);
            auto temp = lru->next;
            remove(lru->next);
            auto entry = temp->val.first;
            map.erase(entry); // clear entry

            map[key] = node;
            addToRight(node);
        }
    }

private:
    // remove a node from linkedlist
    void remove(ListNodeD *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev; // connect prev and next
        node->prev = nullptr;          // remove
        node->next = nullptr;
        size--;
    };

    void addToRight(ListNodeD *node)
    {
        mru->prev->next = node;
        node->prev = mru->prev;
        node->next = mru;
        mru->prev = node;
        size++;
    };

    unordered_map<int, ListNodeD *>
        map;
    ListNodeD *lru;
    ListNodeD *mru;
    int size = 0;
    int capacity = 0;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */