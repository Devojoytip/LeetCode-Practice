// https://leetcode.com/problems/cousins-in-binary-tree-ii

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
    TreeNode* replaceValueInTree(TreeNode* r) {
        r->val=0;
        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty())
        {
            int n=q.size();
            int tot=0;
            vector<TreeNode*> v;

            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left) 
                {
                    q.push(temp->left);
                    tot+=temp->left->val;
                }
                if(temp->right) 
                {
                    q.push(temp->right);
                    tot+=temp->right->val;
                }
            }

            for(auto node:v)
            {
                int sum=tot;
                if(node->left)  sum -= node->left->val;
                if(node->right) sum -= node->right->val;
                if(node->left)  node->left->val = sum;
                if(node->right) node->right->val = sum;
            }
        }

        return r;
    }
};
