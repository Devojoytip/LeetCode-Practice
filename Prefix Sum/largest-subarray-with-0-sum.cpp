// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        // Your code here
        map<int,int> mp;
        int sum=0,ans=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            
            if(sum==0) ans=max(ans,i+1);
            
            if(mp.find(sum)!=mp.end()) ans=max(ans,i-mp[sum]);
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        
        return ans;
    }
};
