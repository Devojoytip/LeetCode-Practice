//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *h, int k)
    { 
        // Complete this method
        // if(!h or !h->next) return h;
        
        // int n=0;
        // struct node *t=h;
        
        // while(t)
        // {
        //     n++;
        //     t=t->next;
        // }
        
        // if(k>n) return h;
        
        // struct node *prev=NULL;
        // struct node *curr=h;
        // struct node *nxt=h;
        // int c=k;
        
        // while(c>0)
        // {
        //     nxt=nxt->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nxt;
        //     c--;
        // }
        
        // if(n-k>0) h->next=reverse(nxt,k);
        
        // return prev;
        
        if(!h or !h->next) return h;

        int n=0;
        struct node* t=h;
        while(t)
        {
            n++;
            t=t->next;
        }
        
        int cnt;
        
        if(k>n) cnt=n;
        else cnt=k;

        struct node* curr=h;
        struct node* nxt=h;
        struct node* prev=NULL;
        
        while(cnt>0)
        {
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt--;
        }

        n-=k;
        if(n>0) h->next=reverse(nxt,k);

        return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends