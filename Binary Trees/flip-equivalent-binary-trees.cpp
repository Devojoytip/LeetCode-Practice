// https://leetcode.com/problems/flip-equivalent-binary-trees

class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) 
    {
        if(!r1 and !r2) return 1;
        if(!r1 and r2) return 0;
        if(r1 and !r2) return 0;

        if(r1->val==r2->val)
        {
            bool op1= flipEquiv(r1->left, r2->left) and flipEquiv(r1->right, r2->right);
            if(op1) return 1;
            return flipEquiv(r1->left, r2->right) and flipEquiv(r1->right, r2->left); // do flip
        }
        return 0;
    }
};
