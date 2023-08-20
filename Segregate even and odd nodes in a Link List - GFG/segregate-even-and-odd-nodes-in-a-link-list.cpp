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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int n, Node *h)
    {
        // code here
        Node *t=h;
        Node *ev=new Node(-1);
        Node *od=new Node(-1);
        Node *evT=ev;
        Node *odT=od;
        
        while(t)
        {
            int d=t->data;
           if(d%2==0) 
           {
               evT->next=new Node(d);
               evT=evT->next;
           }
           else
           {
               odT->next=new Node(d);
               odT=odT->next;
           }
            t=t->next;  
        }

        if(ev->next) h=ev->next;
        if(od->next) evT->next=od->next;

        return h;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends