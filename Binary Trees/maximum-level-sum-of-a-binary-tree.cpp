// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* r) {
        
        if(!r) return 0;

        queue<TreeNode*> q;
        q.push(r);
        long long int lev=0,sum=0,maxLev=0,maxSum=0;

        while(!q.empty())
        {
            lev++;
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

            if(maxSum<sum or lev==1) 
            {
                maxLev=lev;
                maxSum=sum;
            }
        }

        return maxLev;
    }
};
