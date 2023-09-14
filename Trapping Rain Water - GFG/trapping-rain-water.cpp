//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n){
        // code here
        long long ans=0, lmax=0, rmax=0;
        int l[n]={0}, r[n]={0};
        
        for(int i=0, j=n-1;i<n and j>=0;i++, j--)
        {
            lmax=max((long long) a[i], lmax);
            rmax=max((long long) a[j], rmax);
            l[i]=lmax;
            r[j]=rmax;
        }
        
        for(int i=0;i<n;i++) ans+=(long long) min(l[i], r[i])-a[i];
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends