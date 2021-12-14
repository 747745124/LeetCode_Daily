#include "header.hpp"
/*
brute force
*/
class Solution
{
public:
    void remove(std::vector<string> &v)
    {
        auto end = v.end();
        for (auto it = v.begin(); it != end; ++it)
        {
            end = std::remove(it + 1, end, *it);
        }

        v.erase(end, v.end());
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, vector<int>> nameList;
        for (int i = 0; i < accounts.size(); i++)
        {
            remove(accounts[i]);
            nameList[accounts[i][0]].push_back(i);
        }
        vector<vector<string>> res;

        for (auto &kv : nameList)
        {
            unordered_map<string, int> presence;

            /* only one name*/
            if (kv.second.size() == 1)
                res.push_back(accounts[kv.second[0]]);

            if (kv.second.size() > 1)
            {

                string name = kv.first;
                vector<unordered_set<string>> temp;
                unordered_map<string, int> place;

                for (int i = 0; i < nameList[name].size(); i++)
                {
                    int index = nameList[name][i];
                    temp.push_back(unordered_set<string>(accounts[index].begin(), accounts[index].end()));

                    for (int j = 1; j < accounts[index].size(); j++)
                    {
                        if (presence.count(accounts[index][j]) == 0)
                        {
                            presence[accounts[index][j]] = index;
                            place[accounts[index][j]] = i;
                        }
                        else
                        // this account has been presented in some people's list
                        //  with the same name
                        {
                            temp[place[accounts[index][j]]].insert(accounts[index].begin() + 1, accounts[index].end());
                            temp.pop_back();
                            break;
                            //merge index with the one in the table
                        }
                    }
                }

                for (auto &elem : temp)
                {
                    auto tmp = vector<string>(elem.begin(), elem.end());
                    res.push_back(tmp);
                }
            }
        }

        for (auto &name : res)
        {
            sort(name.begin(), name.end());
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"Mary", "mary@mail.com"},
                                       {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> res = s.accountsMerge(accounts);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}