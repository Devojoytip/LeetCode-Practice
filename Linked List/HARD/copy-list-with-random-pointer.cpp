// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        
        Node* ptr=h;

        // made copies of all nodes
        while(ptr)
        {
            Node* newnode=new Node(ptr->val);
            newnode->next=ptr->next;
            ptr->next=newnode;
            ptr=ptr->next->next;
        }

        // linking of random pointers of copies
        ptr=h;
        while(ptr)
        {
            if(ptr->random) ptr->next->random=ptr->random->next;
            ptr=ptr->next->next;
        }

        // linking of next pointers of org nodes and copies
        ptr=h;
        Node* dummy=new Node(-1);
        Node* temp=dummy;

        while(ptr)
        {
            temp->next=ptr->next;
            ptr->next=ptr->next->next;
            ptr=ptr->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};
