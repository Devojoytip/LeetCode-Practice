/*

https://leetcode.com/problems/maximum-binary-tree-ii/

More challenges
545. Boundary of Binary Tree
958. Check Completeness of a Binary Tree
2049. Count Nodes With the Highest Score
*/

class Solution {
public:

    TreeNode* insertIntoMaxTree(TreeNode* r, int x) {

        // assume the arr with x being the last ele of the arr
        if(!r) return new TreeNode(x);

        // thus if bigger it will become root and entire tree on its left and as it does not have any right so right always null
        if(r->val<x) return new TreeNode(x,r,NULL);

        // else it will always be on the right of the tree
        r->right = insertIntoMaxTree(r->right, x);
        return r;
    }
};
