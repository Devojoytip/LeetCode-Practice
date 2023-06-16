// https://leetcode.com/problems/binary-tree-level-order-traversal-ii 

class Solution {
public:
    int depth(TreeNode* r)
    {
        if(!r) return 0;
        return 1 + max(depth(r->left), depth(r->right));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* r) {
        
        if(!r) return {};
        
        int dep=depth(r);
        vector<vector<int>> res(dep, vector<int>({}));
        
        queue<TreeNode*> q;
        q.push(r);
        dep--;
        
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                res[dep].push_back(temp->val);
            }
            dep--;
        }

        return res;
    }
};
