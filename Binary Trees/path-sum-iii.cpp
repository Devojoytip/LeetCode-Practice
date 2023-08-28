// https://leetcode.com/problems/path-sum-iii

class Solution {
public:

    int sol(TreeNode* r, long s) 
    {
        if(!r) return 0;
        
        if(r->val==s) return 1 + sol(r->left,s-r->val) + sol(r->right,s-r->val);
        
        return sol(r->left,s-r->val) + sol(r->right,s-r->val);
    }

    int pathSum(TreeNode* r, int s) 
    {
        if(!r)return 0;
        
        return sol(r,(long)s)+pathSum(r->left,(long)s)+pathSum(r->right,(long)s);
    }
};
