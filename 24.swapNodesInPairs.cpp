#include "header.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
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
        for (int i = 0; i < n / 2; i++)
        {
            swap(nodeVals[2 * i], nodeVals[2 * i + 1]);
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    s.swapPairs(head);
}