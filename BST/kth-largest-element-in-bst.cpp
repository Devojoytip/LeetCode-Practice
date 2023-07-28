// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution
{
    public:
    void inorder(Node* r, vector<int> &v)
    {
        if(!r) return;
        inorder(r->left,v);
        v.push_back(r->data);
        inorder(r->right,v);
    }

    int kthLargest(Node *r, int k)
    {
        //Your code here
        vector<int> v;
        inorder(r,v);

        return v[v.size()-k];
    }
};
