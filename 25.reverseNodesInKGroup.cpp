#include "header.hpp"
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<int> nodeVals;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            auto tmp = curr;
            nodeVals.push_back(curr->val);
            curr = curr->next;
        }
        int n = nodeVals.size();
        if (!n)
            return nullptr;
        if (n == 1)
            return new ListNode(nodeVals[0]);
        for (int i = 0; i < n / k; i++)
        {
            reverse(nodeVals.begin() + k * i, nodeVals.begin() + k * i + k);
        }

        ListNode *node = new ListNode(nodeVals[0]);
        ListNode *header = node;
        for (int i = 0; i < n - 1; i++)
        {
            node->next = new ListNode(nodeVals[i + 1]);
            node = node->next;
        }
        return header;
    }
};
int main()
{
    Solution s;
    vector<int> hey{1, 2, 3, 4};

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    s.reverseKGroup(head, 2);
}