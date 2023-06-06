// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list 

class Solution {
public:
    int pairSum(ListNode* h) {
        ListNode* t=h;
        vector<int> v;

        while(t!=NULL)
        {
            v.push_back(t->val);
            t=t->next;
        }

        int n=v.size(),ans=-1;

        for(int i=0;i<=n/2;i++) ans=max(v[i]+v[n-1-i],ans);

        return ans;
    }
};
