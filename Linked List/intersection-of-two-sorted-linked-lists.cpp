// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists

Node* findIntersection(Node* h1, Node* h2)
{
    // Your Code Here
    if(!h1 or !h2) return NULL;
    
    Node* h=new Node(-1);
    Node*t=h;
    Node* t1=h1;
    Node* t2=h2;
    
    while(t1 and t2)
    {
        if(t1->data>t2->data) t2=t2->next;
        
        else if(t1->data<t2->data) t1=t1->next;
        
        else
        {
            t->next=new Node(t1->data);
            t=t->next;
            t1=t1->next;
            t2=t2->next;
        }
    }
    
    return h->next;
}
