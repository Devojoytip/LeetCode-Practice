// https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
 /*
s=1, e=m;
check for each mid ie pow(mid, n) == m , return mid
                                  <m - s=mid+1 
                                  >m - e=mid-1
*/
class Solution{
	public:
	
	int f(int num, int n, int m)
	{
	    long long int ans=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        ans*=num;
	        if(ans>m) return 2;
	        if(ans==m and i==n) return 1;
	    }
	    
	    return 0;
	}
	
	int recur(int n, int m)
	{
	    // Code here.
	    int s=1, e=m;
	    
	    while(s<=e)
	    {
	        int mid=(s+e)/2;
	        
	        int res=f(mid,n,m);
	        
	        if(res==1) return mid;
	        
	        if(res==2) e=mid-1;
	        
	        else s=mid+1;
	    }
	    
	    return -1;
	}  
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    return recur(n,m);
	}  
};
