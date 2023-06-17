// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* r) {
        queue<TreeNode*> q;
        q.push(r);
        bool flag=0;

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(!curr) flag=1;
            else
            {
                if(flag) return 0; // already got a null node before this
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return 1;
    }
};
