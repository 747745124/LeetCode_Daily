#include "header.hpp"

class LRUCache
{
    unordered_map<int, ListNodeD *> map;
    ListNodeD *lru;
    ListNodeD *mru;
    int curr_size = 0;
    int capacity = 0;


public:
    LRUCache(int capacity){
        this->capacity = capacity;
        lru = new ListNodeD(-1, -1);
        mru = new ListNodeD(-1, -1);
        lru->next = mru;
        mru->prev = lru;
    };

private:
    void remove(ListNodeD *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;          // remove
        node->next = nullptr;
        curr_size--;
    };

    void addToRight(ListNodeD *node){
        mru->prev->next = node;
        node->prev = mru->prev;
        node->next = mru;
        mru->prev = node;
        curr_size++;
    };



};

