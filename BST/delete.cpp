// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* r, int k) 
    {
        if(!r)return r;

        else if(r->val>k) r->left=deleteNode(r->left,k);

        else if(r->val<k) r->right=deleteNode(r->right,k);

        else{
            if(!r->left and !r->right)
            {
                delete r;
                return NULL;
            }
            if(r->left and !r->right)
            {
                TreeNode* temp=r->left;
                r->left=NULL;
                delete r;
                return temp;
            }
            if(!r->left and r->right)
            {
                TreeNode* temp=r->right;
                r->right=NULL;
                delete r;
                return temp;
            }
            else{
                TreeNode* temp=r->left;
                while(temp->right)temp=temp->right;
                int leftMax=temp->val;
                r->val=leftMax;
                r->left=deleteNode(r->left,leftMax);
                return r;
            }
        }
        return r;
    }
};
