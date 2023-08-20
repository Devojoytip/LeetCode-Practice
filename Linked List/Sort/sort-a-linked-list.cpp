// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* merge(Node* f, Node* s)
    {
        if(!f and !s) return NULL;
        if(f and !s) return f;
        if(!f and s) return s;
        
        Node* h=new Node(-1);
        Node* t=h;
        
        while(f and s)
        {
            if(f->data<s->data)
            {
                t->next=new Node(f->data);
                t=t->next;
                f=f->next;
            }
            
            else
            {
                t->next=new Node(s->data);
                t=t->next;
                s=s->next;
            }
        }
        
        if(f) t->next=f;
        if(s) t->next=s;
        
        return h->next;
    }
    
    Node* mergeSortFn(Node* h)
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
        
        f=mergeSortFn(f);
        s=mergeSortFn(s);
        return merge(f,s);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        Node* res=mergeSortFn(head);
        return res;
    }
};
