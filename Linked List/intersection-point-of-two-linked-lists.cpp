// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        
        if(!h1 or !h2) return NULL;
    
        ListNode* t1=h1;
        ListNode* t2=h2;
        
        while(t1!=t2)
        {
            t1 = (!t1) ? h2 : t1->next;
            t2 = (!t2) ? h1 : t2->next;
        }
        
        return t1;
    }
};
