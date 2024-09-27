#include "header.hpp"
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        auto prev = head;
        auto fast = head;
        auto slow = head;

        while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        slow = nullptr;

        return head;
    }
};