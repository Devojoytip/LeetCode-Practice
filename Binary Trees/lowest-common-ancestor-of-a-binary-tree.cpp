// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

class Solution {
public:
    TreeNode* sol(TreeNode* r, TreeNode* p, TreeNode* q) {
        
        if(!r) return r;

        if(r->val==p->val or r->val==q->val) return r;

        TreeNode* leftAns = sol(r->left,p,q);
        TreeNode* rightAns = sol(r->right,p,q);

        if(leftAns and rightAns) return r;

        if(leftAns) return leftAns;

        return rightAns;
    }

    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        
        return sol(r,p,q);
    }
};
