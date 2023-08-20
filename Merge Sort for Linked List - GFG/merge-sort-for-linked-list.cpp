//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* merge(Node* f, Node* s)
    {
        if(!f and !s) return NULL;
        if(f and !s) return f;
        if(!f and s) return s;
        
        Node* h=new Node(-1);
        Node* t=h;
        
        while(f and s)
        {
            if(f->data<s->data)
            {
                t->next=new Node(f->data);
                t=t->next;
                f=f->next;
            }
            
            else
            {
                t->next=new Node(s->data);
                t=t->next;
                s=s->next;
            }
        }
        
        if(f) t->next=f;
        if(s) t->next=s;
        
        return h->next;
    }
    
    Node* mergeSortFn(Node* h)
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
        
        f=mergeSortFn(f);
        s=mergeSortFn(s);
        return merge(f,s);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        Node* res=mergeSortFn(head);
        return res;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends