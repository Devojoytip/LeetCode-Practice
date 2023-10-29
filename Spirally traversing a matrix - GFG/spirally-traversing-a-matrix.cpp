//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > v, int r, int c) 
    {
        // code here 
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int idx=0,x=0,y=0;
        vector<int> res;
        vector<vector<int> > vis(r,vector<int>(c,0));
        
        for(int i=0;i<r*c;i++)
        {
            res.push_back(v[x][y]);
            vis[x][y]=1;
            int X=x+dx[idx];
            int Y=y+dy[idx];
            
            if(X<0 or X>=r or Y<0 or Y>=c or vis[X][Y]) idx=(idx+1)%4;
            x+=dx[idx];
            y+=dy[idx];
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends