//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmallerEqual(vector<int> &v, int num)
    {
        int s=0, e=v.size()-1, cnt=0;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            if(v[mid]<=num) 
            {
                cnt=mid+1;
                s=mid+1;
            }
            else e=mid-1;
        }
        
        return cnt;
    }
    
    int median(vector<vector<int>> &v, int r, int c){
        // code here 
        int s=1, e=2000;
        
        while(s<=e)
        {
            int mid=(s+e)/2, cnt=0;
            
            for(int i=0;i<r;i++) cnt+=countSmallerEqual(v[i], mid);
            
            if(cnt<=(r*c)/2) s=mid+1;
            
            else e=mid-1;
        }
        
        return s;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends