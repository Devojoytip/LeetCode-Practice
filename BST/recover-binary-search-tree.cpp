// https://leetcode.com/problems/recover-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void helper(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* & prev)
    {
        if(!root) return;

        helper(root->left, first, second, prev);

        if(prev and root->val < prev->val)
        {
            if(!first) first = prev;
            second = root;
        }

        prev = root;

        helper(root->right, first,second, prev);
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        TreeNode *first , *second, *prev;
        first = second = prev = NULL;

        helper(root, first, second, prev);

        if(first and second) swap(first->val, second->val);
    }
};
