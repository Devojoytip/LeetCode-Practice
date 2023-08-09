// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        // Your code here
        
        int sum=0, ans=0;
        
        unordered_map<int, int> mp;
        
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            
            if(sum==0) ans=max(ans, i+1);
            
            int rem=sum;
            
            if(mp.find(sum)!=mp.end()) ans=max(ans, i-mp[sum]);
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        
        return ans;
    }
};
