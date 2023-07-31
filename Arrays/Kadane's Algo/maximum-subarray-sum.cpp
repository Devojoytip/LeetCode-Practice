// https://leetcode.com/problems/maximum-subarray
// Kadane's Algo

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        long long sum=0, ans=-1e9;
        
        for(int i=0;i<n;i++) 
        {
            sum+=a[i];
            
            ans=max(ans, sum);
            
            if(sum<0) sum=0;
        }
        
        return ans;
    }
};
