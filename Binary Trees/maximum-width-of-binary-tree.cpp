// https://leetcode.com/problems/maximum-width-of-binary-tree

class Solution {
public:
    int widthOfBinaryTree(TreeNode* r) {
        
        if(!r) return 0;

        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({r,0});

        while(q.size())
        {
            int n=q.size();
            
            ans=max(q.back().second-q.front().second+1,ans);

            while(n--)
            {
                auto curr=q.front();
                q.pop();

                TreeNode* node=curr.first;
                long long int idx=curr.second;

                if(node->left) q.push({node->left,(long long)idx*2+1});
                if(node->right) q.push({node->right,(long long)idx*2+2});
            }
        }

        return ans;
    }
};
