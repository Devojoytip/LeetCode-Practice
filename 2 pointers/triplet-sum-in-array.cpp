// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        sort(a,a+n);
        
        for(int i=0;i<n-2 and a[i]<x;i++)
        {
            if(i==0 or a[i]!=a[i-1])
            {
                int s=i+1, e=n-1;
                int rem=x-a[i];
                
                while(s<e)
                {
                    if(a[s]+a[e]==rem) return 1;
                    
                    else if(a[s]+a[e]>rem) e--;
                    
                    else s++;
                }
            }
        }
        
        return 0;
    }

};
