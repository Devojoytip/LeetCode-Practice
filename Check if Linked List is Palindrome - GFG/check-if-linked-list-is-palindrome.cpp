//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node *h)
    {
        if(!h or !h->next) return h;
        Node *curr=h;
        Node *nxt=h;
        Node *prev=NULL;
        
        while(nxt)
        {
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
    
    bool isPalindrome(Node *h)
    {
        //Your code here
        Node *f=h;
        Node *s=h;
        
        while(f and f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        
        Node* t=reverse(s);
        
        
        while(h and t)
        {
            if(h->data==t->data)
            {
                h=h->next;
                t=t->next;
            }
            else return 0;
        }
        
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends