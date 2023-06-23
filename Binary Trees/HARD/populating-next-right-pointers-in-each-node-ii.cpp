// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* r) {
        if(!r) return r;

        Node *curr=r, *nxt=NULL, *nextLevIterator=NULL;

        while(curr)
        {
            if(curr->left)
            {
                if(nextLevIterator)
                {
                    nextLevIterator->next=curr->left;
                    nextLevIterator=nextLevIterator->next;
                }
                else nxt=nextLevIterator=curr->left;
            }

            if(curr->right)
            {
                if(nextLevIterator)
                {
                    nextLevIterator->next=curr->right;
                    nextLevIterator=nextLevIterator->next;
                }
                else nxt=nextLevIterator=curr->right;
            }

            if(curr->next) curr=curr->next;

            else 
            {
                curr=nxt;
                nxt=nextLevIterator=NULL;
            }
        }

        return r;
    }
};
