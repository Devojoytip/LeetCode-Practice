// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        
        if(!r)return r;

        if(r->val==p->val or r->val==q->val) return r;

        if(r->left and r->right)
        {
            if((r->left->val==p->val and r->right->val==q->val) or (r->left->val==q->val and r->right->val==p->val)) return r;
        }

        if(r->val<p->val and r->val<q->val) return lowestCommonAncestor(r->right,p,q);

        if(r->val>p->val and r->val>q->val) return lowestCommonAncestor(r->left,p,q);

        return r;
    }
};
