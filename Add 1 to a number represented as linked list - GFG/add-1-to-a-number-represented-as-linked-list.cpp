//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* rev(Node *h) 
    {
        if(!h or !h->next) return h;
        
        Node *curr=h;
        Node *nxt=h;
        Node *prev=NULL;
        
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
    
    Node* add(Node *h) 
    {
        if(!h) return h;
        Node *t=h;
        Node *prev=t;
        int carry=1;
        
        while(t)
        {
            if(carry) 
            {
                int num=t->data+carry; 
                t->data=num%10;
                carry=num/10;
                prev=t;
                t=t->next;
            }
            else break;
        }
        
        if(carry) prev->next=new Node(1);
        
        return h;
    }
    
    Node* addOne(Node *h) 
    {
        // Your Code here
        // return head of list after adding one
        Node* t=rev(h);
        t=add(t);
        t=rev(t);
        
        return t;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends