// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* r) {
        
        if(!r) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool dir=0;

        q.push(r);

        while(q.size())
        {
            int n=q.size();
            vector<int> v;

            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(dir) reverse(v.begin(),v.end());

            res.push_back(v);
            dir=!dir;
        }

        return res;
    }
};
