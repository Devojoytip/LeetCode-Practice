// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> distanceK(TreeNode* r, TreeNode* t, int k) {
        
        if(!r) return {};

        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[r]=new TreeNode(-1);
        q.push(r);

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left) 
                {
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }

                if(curr->right) 
                {
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }   

        q.push(t);
        int dis=0;
        vector<int> vis(501,0);
        vis[t->val]=1;
        vector<int> res;

        while(!q.empty() and dis<k)
        {
            int n=q.size();
            dis++;
            
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left and !vis[curr->left->val]) 
                {
                    vis[curr->left->val]=1;
                    q.push(curr->left);
                }

                if(curr->right and !vis[curr->right->val]) 
                {
                    vis[curr->right->val]=1;
                    q.push(curr->right);
                }

                if(parent[curr]->val!=-1 and !vis[parent[curr]->val])
                {
                    vis[parent[curr]->val]=1;
                    q.push(parent[curr]);
                }
            }
        }   

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }

        return res;
    }
};
