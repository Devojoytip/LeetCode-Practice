//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *rev(Node *h)
    {
        // your code goes here
        if(!h or !h->next) return h;
        
        Node* curr=h;
        Node* nxt=h;
        Node* prev=NULL;
        
        while(nxt)
        {
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
    Node *compute(Node *h)
    {
        // your code goes here
        Node* t=new Node(-1);
        t->next=rev(h);
        Node* curr=t;
        Node* nxt=t->next;
        
        while(nxt)
        {
            if(nxt->data<curr->data) nxt=nxt->next;
            else
            {
                curr->next=nxt;
                curr=curr->next;
                nxt=nxt->next;
            }
        }
        
        if(curr) curr->next=nxt;
        return rev(t->next);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends