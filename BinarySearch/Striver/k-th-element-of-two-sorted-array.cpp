// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution{
    public:
    
    int sol(int a[], int b[], int n, int m, int k)
    {
        
        int s=max(0,k-m), e=min(k,n);
        
        while(s<=e)
        {
            int c1=(s+e)/2;
            int c2=k-c1;
            
            int l1 = (c1==0) ? INT_MIN : a[c1-1];
            int l2 = (c2==0) ? INT_MIN : b[c2-1];
            int r1 = (c1==n) ? INT_MAX : a[c1];
            int r2 = (c2==m) ? INT_MAX : b[c2];
            
            if(l1<=r2 and l2<=r1) return max(l1,l2);
            
            else if(l1>r2) e=c1-1;
            
            else s=c1+1;
        }
        
        return -1;
    }
    
    int kthElement(int a[], int b[], int n, int m, int k)
    {
        if(m+n<k) return -1;
        
        if(m>n) return sol(a,b,n,m,k);
        
        return sol(b,a,m,n,k);
    }
};
