// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
public:

    int recur(TreeNode* r, long long &maxi) 
    {
        if(!r) return 0;

        long long leftAns=max(0,recur(r->left,maxi));   
        long long rightAns=max(0,recur(r->right,maxi));  

        maxi=max(maxi,r->val+leftAns+rightAns);

        return r->val+max(leftAns,rightAns);
    }

    int maxPathSum(TreeNode* r) {
      
        long long maxi=-1e9;
        recur(r,maxi);
        return maxi;
    }
};
