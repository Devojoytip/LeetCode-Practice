// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* merge(Node* f, Node* s)
    {
        if(!f and !s) return NULL;
        if(f and !s) return f;
        if(!f and s) return s;
        
        Node* h=new Node(-1);
        Node* t=h;
        
        while(f and s)
        {
            if(s->data<f->data)
            {
                t->next=new Node(s->data);
                t=t->next;
                s=s->next;
            }
            
            else
            {
                t->next=new Node(f->data);
                t=t->next;
                f=f->next;
            }
        }
        
        if(s) t->next=s;
        if(f) t->next=f;
        
        return h->next;
    }
    
    Node* mergeSort(Node *h)
    {
        if(!h or !h->next) return h;
        
        Node* f=h->next;
        Node* s=h;
        
        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        
        f=s->next;
        s->next=NULL;
        s=h;
        
        f=mergeSort(f);
        s=mergeSort(s);
        
        return merge(f,s);
    }
    
    Node* segregate(Node *h) {
        
        // Add code here
        return mergeSort(h);
    }
};
