//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        
        // your code here
        int ele=-1,c=0,f=0,m=(int)n/2+1;
        
        for(int i=0;i<n;i++)
        {
            if(c==0) c++, ele=a[i];
            else if(ele!=a[i]) c--;
            else c++;
        }
        
        for(int i=0;i<n;i++) 
        {
            if(a[i]==ele) f++;
        }
        
        return (f>=m) ? ele : -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends