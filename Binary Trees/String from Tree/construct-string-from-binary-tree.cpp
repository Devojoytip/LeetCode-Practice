// https://leetcode.com/problems/construct-string-from-binary-tree

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
    void recur(TreeNode* r,string &s) {
        
        if(!r) return;
        s+=to_string(r->val);
        
        if(r->left)
        {
            s+="(";
            recur(r->left,s);
            s+=")";
        }

        if(r->right)
        {
            if(!r->left) s+="()";
            s+="(";
            recur(r->right,s);
            s+=")";
        }
        
    }
    string tree2str(TreeNode* r) {
        string s="";
        recur(r,s);
        return s;
    }
};
