// https://leetcode.com/problems/binary-tree-right-side-view

class Solution {
public:
    vector<int> rightSideView(TreeNode* r) {
        
        if(!r) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(r);

        while(q.size())
        {
            int s=q.size();

            while(s>0)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                if(s==1) res.push_back(curr->val);
                s--;
            }
        }

        return res;
    }
};
