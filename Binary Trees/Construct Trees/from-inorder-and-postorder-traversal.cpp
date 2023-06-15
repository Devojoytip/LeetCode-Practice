// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* recur(vector<int>& in, vector<int>& post,int is,int ie,int ps,int pe) {

        if(is==ie) return new TreeNode(in[is]);
        
        if(is>ie) return NULL;
        
        int i=is,len=0;
        while(in[i]!=post[pe])
        {
            i++;
            len++;
        }
        
        TreeNode* node=new TreeNode(in[i]);
        node->left=recur(in,post,is,i-1,ps,ps+len-1);
        node->right=recur(in,post,i+1,ie,ps+len,pe-1);

        return node;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return recur(in,post,0,in.size()-1,0,post.size()-1);
    }
};
