// https://leetcode.com/problems/same-tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL and q!=NULL) return 0;

        if(p!=NULL and q==NULL) return 0;
        
        if(p==NULL and q==NULL) return 1;
        
        return p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    } 
};
