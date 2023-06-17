// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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

 // INORDER with NO EXTRA SPACE
class Solution {
public:

    void inorder(TreeNode *r,int &ans,int &prev){
        
        if(!r) return;
        
        inorder(r->left,ans,prev);
        
        if(prev==-1) prev=r->val;
        
        else
        {
            ans=min(r->val-prev,ans);
            prev=r->val;
        }

        inorder(r->right,ans,prev);
        
    }

    int minDiffInBST(TreeNode* r) {

        if(!r or (!r->left and !r->right)) return 0;

        int ans=INT_MAX,prev=-1;
        inorder(r,ans,prev);
        return ans;
    }
};
