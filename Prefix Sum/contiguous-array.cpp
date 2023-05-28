/* 
https://leetcode.com/problems/contiguous-array

Prefix sum
Longest sum subarray
Diff - replace 0 with -1
thus sum of subarray with eq no of 0s & 1s = 0

*/
class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int i=0,j=0,n=v.size(),ans=0,k=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0) v[i]=-1;
        }
        map<int,int>mp;

        for(int i=0;i<n;i++)
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

        return ans;
    }
};
