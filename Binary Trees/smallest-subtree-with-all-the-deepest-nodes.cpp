// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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

    TreeNode* LCA(TreeNode* r,TreeNode* p,TreeNode* q) 
    {
        if(!r) return r;
        if(r==p or r==q) return r;
        TreeNode* leftAns=LCA(r->left,p,q);   
        TreeNode* rightAns=LCA(r->right,p,q);   
        if(leftAns and rightAns) return r;
        if(leftAns) return leftAns;
        return rightAns;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* r) {
        queue<TreeNode*> q;
        q.push(r);

        TreeNode* first=NULL;
        TreeNode* last=NULL;

        while(!q.empty())
        {
            first=q.front();
            last=q.back();

            int n=q.size();

            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return LCA(r,first,last);
    }
};
