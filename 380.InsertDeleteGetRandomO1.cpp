#include "header.hpp"
//using vector to simulate
class RandomizedSet
{

public:
    vector<int> arr;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (find(arr.begin(), arr.end(), val) != arr.end())
            return false;
        arr.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (find(arr.begin(), arr.end(), val) == arr.end())
            return false;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            if (*it == val)
            {
                it = arr.erase(it);
            }
            else
            {
                ++it;
            }
        }
        return true;
    }

    int getRandom()
    {
        /* initialize random seed: */
        srand(time(NULL));

        /* generate secret number between 1 and 10: */
        int idx = rand() % arr.size();
        return arr.at(idx);
    }
};

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(3);
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */