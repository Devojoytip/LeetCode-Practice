// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// prefix sum - max length subarray
// instead of searching k we have to search for max subarray of len = total-k
// to get min operations
// ONLY DIFF : 
// 1. k = total - x 
// 2. ans = n - maxLength

class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        map<int,int> mp;
        int ans=-1,sum=0,i,total=0,k;
        for(auto it:v) total+=it;
        k=total-x;
        if(k==0) return v.size();

        for(i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum==k) ans=max(ans,i+1);
            else
            {
                int rem=sum-k;
                if(mp.find(rem)!=mp.end())
                {
                    ans=max(ans,i-mp[rem]);
                }
            }
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }

        return (ans==-1) ? -1 : v.size()-ans;  
    }
};

