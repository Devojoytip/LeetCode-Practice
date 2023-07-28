// https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
public:
    void inorder(TreeNode* r, vector<int> &v)
    {
        if(!r) return;
        inorder(r->left,v);
        v.push_back(r->val);
        inorder(r->right,v);
    }

    int kthSmallest(TreeNode* r, int k) {
        vector<int> v;
        inorder(r,v);

        return v[k-1];
    }
};
