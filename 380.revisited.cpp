#include "header.hpp"
class RandomizedSet
{
public:
    unordered_map<int, int> val_to_index;
    vector<int> vals;
    RandomizedSet()
    {
        vals.clear();
        val_to_index.clear();
    }

    bool insert(int val)
    {
        if (val_to_index.find(val) != val_to_index.end())
            return false;
        vals.push_back(val);
        val_to_index[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (val_to_index.find(val) == val_to_index.end())
            return false;
        iter_swap(vals.begin() + vals.size() - 1, vals.begin() + val_to_index[val]);
        val_to_index.erase(val);
        vals.pop_back();
        return true;
    }

    int getRandom()
    {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */