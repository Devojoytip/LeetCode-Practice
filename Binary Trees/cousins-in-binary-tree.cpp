// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* r, int x, int y) {

        queue<TreeNode*> q;
        q.push(r);
        TreeNode* pX=NULL;TreeNode*pY=NULL; // store the parent as we need to check the parents too

        while(!q.empty())
        {
            int n=q.size();
            
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) 
                {
                    q.push(temp->left);
                    if(temp->left->val==x) pX=temp;
                    if(temp->left->val==y) pY=temp;
                }
                if(temp->right) 
                {
                    q.push(temp->right);
                    if(temp->right->val==x) pX=temp;
                    if(temp->right->val==y) pY=temp;
                }
            }
            if(pX and pY) 
            {
                if(pX!=pY) return 1;
            }
            pX=NULL,pY=NULL;
        }

        return 0;
    }
};
