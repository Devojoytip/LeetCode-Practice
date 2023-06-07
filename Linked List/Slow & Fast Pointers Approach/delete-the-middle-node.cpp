// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

class Solution {
public:
    ListNode* deleteMiddle(ListNode* h) {
        if(!h or !h->next) return NULL;
        
        ListNode* fast=h;
        ListNode* slow=h;
        ListNode* prev=NULL;

        while(fast and fast->next)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        delete slow;
        return h;
    }
};
