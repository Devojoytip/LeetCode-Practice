// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* h)
    {
        // your code here
        if(h==NULL or h->next==NULL) return 0;
        
        Node *f=h, *s=h;

        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;

            if(f==s) return 1;
        }
        
        return 0;
    }
};
