//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

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