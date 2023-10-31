//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string t,string p){
        //Code Here
        
        int n=t.size(), m=p.size();
        vector<int> lps(m+1, 0);
        compute(lps,p);
        
        int i=0,j=0,ans=-1;
        
        while((n-i)>=(m-j))
        {
            if(t[i]==p[j])
            {
                i++;
                j++;
            }
            
            if(j==m)
            {
                ans=i-j;
                j=lps[j-1];
            }
            
            else if(i<n and t[i]!=p[j])
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        
        return (ans==-1) ? -1 : ans+1;
    }
    
    void compute(vector<int> &lps, string p)
    {
        lps[0]=0;
        int i=1, len=0;
        
        while(i<p.size())
        {
            if(p[i]==p[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0) len=lps[len-1];
                
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends