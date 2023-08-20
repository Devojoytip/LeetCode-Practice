//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
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


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends