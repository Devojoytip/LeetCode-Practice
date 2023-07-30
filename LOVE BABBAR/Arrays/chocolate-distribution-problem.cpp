// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> v, long long n, long long m){
        
        sort(v.begin(),v.end());
        long long ans=1e9;
        
        for(int i=0;i+m<=n;i++)
        {
            ans=min(ans,v[i+m-1]-v[i]);
        }
        
        return ans;
    }   
};
