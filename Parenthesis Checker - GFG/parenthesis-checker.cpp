//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string a)
    {
        // Your code here
        stack<char> s;
        
        for(int i=0;i<a.size();i++)
        {
            char c=a[i];
            
            if(c=='{' or c=='[' or c=='(') s.push(c);
            
            else
            {
                if(c=='}')
                {
                    if(s.size() and s.top()=='{') s.pop();
                    else return 0;
                }
                
                else if(c==']')
                {
                    if(s.size() and s.top()=='[') s.pop();
                    else return 0;
                }
                
                else if(c==')')
                {
                    if(s.size() and s.top()=='(') s.pop();
                    else return 0;
                }
            }
        }
        
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends