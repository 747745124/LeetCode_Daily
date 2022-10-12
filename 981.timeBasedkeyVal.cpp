#include "header.hpp"
class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        obj[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {

        if (obj.count(key) == 0)
            return "";
        auto &stamps = obj[key];
        map<int, string>::iterator it = stamps.begin();
        advance(it, stamps.size() - 1);
        if (it->first < timestamp)
            return it->second;

        int low = 0;
        int high = stamps.size();

        while (low <= high)
        {
            int mid = (low + high) / 2;
            it = stamps.begin();
            advance(it, mid);
            if (it->first > timestamp)
                high = mid - 1;
            else if (it->first < timestamp)
                low = mid + 1;
            else
                return it->second;
        }

        it = stamps.begin();
        if (low == 0)
            return "";
        advance(it, low - 1);
        return it->second;
    }

private:
    unordered_map<string, map<int, string>> obj;
};

int main()
{
    TimeMap *obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 3) << endl;
    obj->set("foo", "bar2", 4);
    obj->set("foo", "bar3", 6);
    obj->set("foo", "bar4", 10);
    obj->set("foo", "bar5", 11);
    cout << obj->get("foo", 7) << endl;
    cout << obj->get("foo", 5) << endl;
    return 0;
}