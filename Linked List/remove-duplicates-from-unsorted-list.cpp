// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *h) 
    {
        // your code goes here
        if(!h or !h->next) return h;
    
        Node *curr=h;
        Node *nxt=h->next;
        
        unordered_map<int,int> vis;
        
        while(nxt)
        {
            if(curr) vis[curr->data]=1; 
            while(nxt and vis[nxt->data]==1)
            {
                nxt=nxt->next;
            }
            curr->next=nxt;
            curr=nxt;
            if(nxt) nxt=nxt->next;
        }
        
        return h;
    }
};
