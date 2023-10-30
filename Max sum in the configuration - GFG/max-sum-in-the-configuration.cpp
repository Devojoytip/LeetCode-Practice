//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
    int tot=0, cf=0;
    
    for(int i=0;i<n;i++)
    {
        tot+=a[i];
        cf+=i*a[i];
    }
    
    int curr_sum=cf, ans=curr_sum;
    
    for(int i=1;i<=n;i++)
    {
        int next_sum=curr_sum - (tot-a[i-1]) + (a[i-1]*(n-1));
        ans=max(ans, curr_sum);
        curr_sum=next_sum;
    }
    
    return ans;
}