//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* rev(struct Node* l)
    {
        struct Node* curr=l;
        struct Node* nxt=l;
        struct Node* prev=NULL;
        
        while(nxt and nxt->next)
        {
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        curr->next=prev;
        
        return curr;
    }
    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        
        if(!l1 and !l2) return l1;
        
        if(l1 and !l2) return l1;
        
        if(!l1 and l2) return l2;
        
        struct Node* t1=rev(l1);
        struct Node* t2=rev(l2);
        struct Node* h=new struct Node(-1);
        struct Node* t=h;
        int carry=0;
        
        while(t1 or t2)
        {
            int sum=carry;
            
            if(t1)
            {
                sum+=t1->data;
                t1=t1->next;
            }
            
            if(t2)
            {
                sum+=t2->data;
                t2=t2->next;
            }
            
            carry=sum/10;
            sum%=10;
            t->next=new struct Node(sum);
            t=t->next;
        }
        
        if(carry) t->next=new struct Node(carry);
        
        return rev(h->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends