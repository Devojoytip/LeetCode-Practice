class Solution {
public:
    int height(TreeNode* r) {
        
        if(!r) return 0;

        return 1 + max(height(r->left), height(r->right));
    }

    int diameterOfBinaryTree(TreeNode* r) {
        
        if(!r) return 0;

        return max({height(r->left)+height(r->right), diameterOfBinaryTree(r->left), diameterOfBinaryTree(r->right)}); 
    }
};
