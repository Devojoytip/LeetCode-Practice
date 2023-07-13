// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* r) 
    {
        vector<vector<int>>res;   
        if(!r) return res;
        
        queue<TreeNode*>q;
        q.push(r);
        
        while(!q.empty())
        {
            vector<int>v;
            int s=q.size();
            
            while(s--)
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            res.push_back(v);
        }
        
        return res;
    }
};
