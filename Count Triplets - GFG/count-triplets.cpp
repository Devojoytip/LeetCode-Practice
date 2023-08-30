//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* h, int k) 
{ 
    // code here.
    struct Node* t3=h;
    struct Node* t1=h;
    
    unordered_map<int, int> mp;
    
    int ans=0;
    
    while(t1 and t1->next)
    {
        struct Node* t2=t1->next;
        int x=t2->data;
        
        while(t2)
        {
            int rem=k-t1->data-t2->data;
            if(mp.find(rem)!=mp.end()) ans++;
            t2=t2->next;
        }
        
        mp[t1->data]=1;
        t1=t1->next;
    }
    
    return ans;
} 