// https://leetcode.com/problems/even-odd-tree


class Solution {
public:
    bool isEvenOddTree(TreeNode* r) {
        
        if(!r) return 0;

        queue<TreeNode*> q;
        q.push(r);
        int lev=-1,num=0;
        bool incr=0,decr=0;

        while(!q.empty())
        {
            lev++;
            num = (lev%2==0) ? 0 : 1e6+1;

            int n=q.size();

            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val%2!=(lev+1)%2) return 0;
                
                if(temp->val%2==0) 
                {
                    if(num<=temp->val) return 0;
                }
                
                else
                {
                    if(num>=temp->val) return 0;
                }
                
                num=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return 1;
    }
};
