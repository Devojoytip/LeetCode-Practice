//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // You need d complete this function

    // avoid space at the starting of the string in "move disk....."
    
    void f(int n, int s, int d, int h, long long &cnt)
    {
        cnt++;
        
        if(n<=1) 
        {
            cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
            return;
        }
        
        f(n-1,s,h,d,cnt);
        
        cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
        
        f(n-1,h,d,s,cnt);
    }
    
    long long toh(int n, int s, int d, int h) 
    {
        // Your code here
        long long cnt=0;
        f(n,s,d,h,cnt);
        return cnt;
    }

};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends