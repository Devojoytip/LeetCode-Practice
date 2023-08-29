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
    int ans=0;

    void f(TreeNode* r, int cnt, bool dir) {
        
        if(!r) return;

        if(dir)
        {
            f(r->left, cnt+1, !dir);
            f(r->left, 0, dir);
        }
        
        else
        {
            f(r->right, cnt+1, !dir);
            f(r->right, 0, dir);
        }

        ans=max(ans, cnt);
    }

    int longestZigZag(TreeNode* r) {
        
        f(r,0,1);
        f(r,0,0);

        return ans;
    }
};
