// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        // Complet the function
        
        int good=0, bad=0, ans=1e9, i=0, j=0;
        
        for(int i=0;i<n;i++) 
        {
            if(a[i]<=k) good++;
        }
        
        while(j<n)
        {
            if(a[j]>k) bad++;
            
            if(j-i+1==good) 
            {
                ans=min(ans,bad);
                if(a[i]>k) bad--;
                i++;
            }
            j++;
        }
        
        return (ans==1e9) ? 0 : ans;
    }
};
