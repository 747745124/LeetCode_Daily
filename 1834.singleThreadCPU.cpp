#include "header.hpp"
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            tasks[i].push_back(i);
        }

        auto comp = [](vector<int> &a, vector<int> &b)
        {
            if (a[1] != b[1])
                return a[1] > b[1];
            return a[2] > b[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        sort(tasks.begin(), tasks.end());
        int curr_time = 0;
        int task_index = 0;
        vector<int> res = {};

        while (res.size() < tasks.size())
        {
            if (pq.empty() && curr_time < tasks[task_index][0])
                curr_time = tasks[task_index][0];

            while (task_index < tasks.size() && curr_time >= tasks[task_index][0])
            {
                pq.push(tasks[task_index]);
                task_index++;
            }

            auto process_time = pq.top()[1];
            auto index = pq.top()[2];
            pq.pop();

            curr_time += process_time;
            res.push_back(index);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    auto res = s.getOrder(tasks);
    for (auto &i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}