// https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* h)
    {
        // your code here
        if(h==NULL or h->next==NULL) return -1;
        
        Node *f=h, *s=h;

        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;

            if(f==s) break;
        }
        
        if(!f or f!=s) return -1;

        s=h;
        while(f!=s)
        {
            f=f->next;
            s=s->next;
        }
        
        return s->data;
    }
};
