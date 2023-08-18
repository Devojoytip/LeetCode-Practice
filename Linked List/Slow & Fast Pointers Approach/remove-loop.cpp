// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* h)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *t=h, *f=h, *s=h;
        
        while(f and f->next) 
        {
            f=f->next->next;
            s=s->next;
            if(f==s) break;
        }
        
        if(s==h)
        {
            while(f->next!=h)
            {
                f=f->next;
            }
            f->next=NULL;
        }
        
        else if(f==s)
        {
            s=h;
            while(s->next!=f->next)
            {
                s=s->next;
                f=f->next;
            }
            f->next=NULL;
        }
    }
};
