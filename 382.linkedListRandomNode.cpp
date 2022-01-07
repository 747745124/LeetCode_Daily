#include "header.hpp"

// reservoir sampling
class Solution
{
private:
    const ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
    }

    int getRandom()
    {
        // we are not allowed to modify the head pointer itself
        // each round we create a new node to do the trick
        auto node = head;
        int res = head->val;
        int i = 1;
        while (node != nullptr)
        {

            // random generate 1~i, only 1 means being selected
            // i should start from 1, or there would be divide by 0 issue
            bool replace = (rand() % (i - 1 + 1)) + 1 == 1;
            if (replace)
                res = node->val;
            node = node->next;
            i++;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */