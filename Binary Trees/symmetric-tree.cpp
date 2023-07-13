// https://leetcode.com/problems/symmetric-tree

class Solution {
public:
    bool solve(TreeNode* p,TreeNode* q)
    {
        if(!p and !q) return 1;

        if(p and !q) return 0;

        if(!p and q) return 0;
    
        return p->val==q->val and solve(p->left,q->right) and solve(p->right,q->left);
    }

    bool isSymmetric(TreeNode* r)
    {
        return solve(r,r);
    }
};
