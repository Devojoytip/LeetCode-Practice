// https://leetcode.com/problems/deepest-leaves-sum

class Solution {
public:
    int deepestLeavesSum(TreeNode* r) {
        
        if(!r) return 0;

        queue<TreeNode*> q;
        q.push(r);
        long long int ans=0,sum=0;

        while(!q.empty())
        {
            int n=q.size();
            sum=0;
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans=sum;
        }

        return ans;
    }
};
