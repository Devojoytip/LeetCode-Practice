// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* h, int k) {
        
        // First calc length of LL
        ListNode* temp=h;
        int len=0;

        while(temp)
        {
            len++;
            temp=temp->next;
        }

        // Reverse for 1st k group only rest done by recursion
        if(len>=k)
        {
            ListNode* curr=h; 
            ListNode* prev=NULL;
            ListNode* nxt=NULL; // Change compared to reverse LL

            for(int i=0;i<k;i++)
            {
                nxt=curr->next; // Change compared to reverse LL
                curr->next=prev;
                prev=curr;
                curr=nxt;
            }

            len-=k;

            // recursive call on rem nodes
            if(len>0) h->next=reverseKGroup(nxt,k);

            // return prev as at last it will be the new head
            return prev;
        }
        
        //return head as the k group is not present to reverse
        return h;
    }
};
