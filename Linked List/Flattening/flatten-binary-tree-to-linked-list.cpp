// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
public:
    void sol(TreeNode* r)
    {
        if(!r) return;

        if(!r->left) 
        {
            sol(r->right);
            return;
        }

        TreeNode* t = r->left;
        while(t->right) t=t->right;
        t->right=r->right;
        
        r->right=r->left;
        r->left=NULL;
        sol(r->right);
    }

    void flatten(TreeNode* r) 
    {
        sol(r);
    }
};
