// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1


class Solution{
  public:

    int smallestSubWithSum(int a[], int n, int x)
    {
        // Your code goes here  
        int i=0,j=0,sum=0,ans=1e9;
        
        while(j<n)
        {
            sum+=a[j];
            
            if(sum>x) 
            {
                
                while(sum>x and i<=j)
                {
                    ans=min(ans,j-i+1);
                    sum-=a[i];
                    i++;
                }
                j++;
            }
            else j++;
        }
        
        return (ans==1e9) ? 0 : ans;
    }
};
