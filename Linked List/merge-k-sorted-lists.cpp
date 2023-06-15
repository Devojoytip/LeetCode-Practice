// https://leetcode.com/problems/merge-k-sorted-lists

class Solution {
public:
    class cmp{
        public:
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& v) {

        int k=v.size();
        if(k==0) return NULL;

        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        
        for(auto it:v) 
        {
            if(it) pq.push(it);
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        // O(N*K log K)
        while(!pq.empty())
        {
            ListNode* curr=pq.top();
            pq.pop();
            temp->next=curr;
            temp=curr;
            if(curr->next) pq.push(curr->next);
        }
        
        temp->next=NULL;
        return dummy->next;
    }
};
