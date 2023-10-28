//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method*/
    int max_path_sum(int a[], int b[], int m, int n)
    {
        int i=0,j=0,sa=0,sb=0,res=0;
        
        while(i<m and j<n)
        {
            if(a[i]<b[j]) 
            {
                sa+=a[i];
                i++;
            }
            
            else if(a[i]>b[j]) 
            {
                sb+=b[j];
                j++;
            }
            
            else
            {
                res+=max(sa,sb)+a[i];
                sa=0;
                sb=0;
                i++;
                j++;
            }
        }
        
        while(i<m) sa+=a[i], i++;
        
        while(j<n) sb+=b[j], j++;
        
        return res+max(sa,sb);
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends