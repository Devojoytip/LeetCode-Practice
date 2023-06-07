// https://leetcode.com/problems/remove-nth-node-from-end-of-list


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        if(!h or !h->next) return NULL;
        
        ListNode* fast=h;
        ListNode* slow=h;
        ListNode* prev=h;

        while(n-- >1) fast=fast->next;
        
        while(fast and fast->next)
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }

        if(prev==slow) h=slow->next;
        else prev->next=slow->next;
        delete slow;
        return h;
    
    }
};
