// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* h) {
        
        if(!h or !h->next) return h;
        ListNode* dummy=new ListNode(-1,h);
        ListNode* curr=dummy;
        ListNode* nxt=h;

        while(nxt)
        {
            if(nxt->next and nxt->val == nxt->next->val)
            {
                while(nxt and nxt->next and nxt->val == nxt->next->val) nxt=nxt->next; 
                curr->next=nxt->next; 
            }
            else curr=curr->next;
            nxt=nxt->next;
        }
        
        return dummy->next;
    }
};
