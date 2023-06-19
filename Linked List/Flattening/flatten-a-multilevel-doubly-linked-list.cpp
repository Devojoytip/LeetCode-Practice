// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* h) {

        Node* t=h;
        stack<Node*> st;

        while(t)
        {
            if(t->child)
            {
                Node* childNode=t->child;
                childNode->prev=t;
                t->child=NULL;
                if(t->next)
                {
                    t->next->prev=NULL;
                    st.push(t->next);
                }
                t->next=childNode;
            }
            if(!t->next and !st.empty())
            {
                Node* curr=st.top();
                st.pop();
                t->next=curr;
                curr->prev=t;
            }
            Node* curr=t;
            t=t->next;
        }

        return h;
    }
};
