// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
 
/**

same as : maximum-level-sum-of-a-binary-tree

 */
class Solution {
public:
    long long int kthLargestLevelSum(TreeNode* r,int k) {

        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;

        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty())
        {
            int n=q.size();
            long long int sum=0;
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            pq.push(sum);
            if(pq.size()>k) pq.pop();

        }

        return (pq.size()<k) ? -1 : pq.top();
    }
};
