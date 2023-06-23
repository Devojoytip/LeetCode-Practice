// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

// Space: O(1)

class Solution {
public:
    void leftConnect(Node* curr, Node* left)
    {
        while(curr)
        {
            left->next=curr->right;
            curr=curr->next;
            left=left->next;

            if(curr)
            {
                left->next=curr->left;
                left=left->next;
            }
        }
    }

    void recur(Node* curr)
    {
        if(!curr or !curr->left) return;
        leftConnect(curr,curr->left);
        recur(curr->left);
    }

    Node* connect(Node* r) {
        if(!r) return r;
        recur(r);
        return r;
    }
};
