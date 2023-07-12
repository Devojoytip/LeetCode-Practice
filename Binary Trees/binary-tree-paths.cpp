// https://leetcode.com/problems/binary-tree-paths

class Solution {
public:

    void recur(TreeNode* r, vector<string> &res, string s)
    {
        int val=r->val;
        s+=to_string(val);

        if(!r->left and !r->right)
        {
            res.push_back(s);
            return;
        }

        s+="->";

        if(r->left) recur(r->left,res,s);

        if(r->right) recur(r->right,res,s);
    }

    vector<string> binaryTreePaths(TreeNode* r) {
        
        if(!r) return {};

        vector<string> res;

        recur(r,res,"");

        return res;
    }
};
