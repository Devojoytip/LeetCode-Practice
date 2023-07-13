// https://leetcode.com/problems/balanced-binary-tree

class Solution {
public:

    int height(TreeNode* r)
    {
        if(!r) return 0;

        return 1 + max(height(r->left), height(r->right));
    }

    bool isBalanced(TreeNode* r) {
        
        if(!r) return 1;

        int lh = height(r->left);
        int rh = height(r->right);

        return abs(lh-rh)<=1 and isBalanced(r->left) and isBalanced(r->right);
    }
};
